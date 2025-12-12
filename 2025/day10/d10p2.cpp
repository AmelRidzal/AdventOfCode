//build "C:/msys64/ucrt64/bin/g++.exe" -std=c++17 -g "C:/Users/am37x/Desktop/AdventOfCode/2025/day10/d10p2.cpp" -o "C:/Users/am37x/Desktop/AdventOfCode/2025/day10/d10p2.exe" -I"C:/msys64/ucrt64/include" -L"C:/msys64/ucrt64/lib" -lglpk
//run C:\Users\am37x\Desktop\AdventOfCode\2025\day10\d10p2.exe



#include <glpk.h>
#include <bits/stdc++.h>
using namespace std;

// trim helpers
static inline string trim(const string &s){
    size_t a = s.find_first_not_of(" \t\r\n");
    if (a == string::npos) return "";
    size_t b = s.find_last_not_of(" \t\r\n");
    return s.substr(a, b - a + 1);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ifstream fin("input");
    if(!fin){
        cerr << "Cannot open in10.txt\n";
        return 1;
    }

    long long total_sum = 0;
    string line;
    while (getline(fin, line)){
        line = trim(line);
        if(line.empty()) continue;

        // tokenize by spaces (the format is: [pattern] (..) (..) ... {a,b,c})
        vector<string> tokens;
        {
            istringstream iss(line);
            string t;
            while(iss >> t) tokens.push_back(t);
        }
        if(tokens.size() < 2) continue;

        // last token is the final vector in braces {..}
        string final_token = tokens.back();
        // Gather button tokens: tokens[1]..tokens[n-2]
        vector<string> button_tokens;
        for(size_t i = 1; i + 1 < tokens.size(); ++i){
            button_tokens.push_back(tokens[i]);
        }

        // parse final vector
        vector<long long> finalv;
        // remove { and }
        if(final_token.front() == '{' && final_token.back() == '}'){
            string inside = final_token.substr(1, final_token.size()-2);
            // split by comma
            istringstream iss(inside);
            string num;
            while(getline(iss, num, ',')){
                num = trim(num);
                if(num.empty()) continue;
                finalv.push_back(stoll(num));
            }
        } else {
            cerr << "Bad final token: " << final_token << "\n";
            continue;
        }

        int rows = (int)finalv.size();
        int cols = (int)button_tokens.size();

        // build add_vals: cols x rows matrix (0/1)
        vector<vector<int>> add_vals(cols, vector<int>(rows, 0));
        for(int c = 0; c < cols; ++c){
            string bt = button_tokens[c];
            // expect format like "(0,1,3)" or "(2)"
            if(bt.size() >= 2 && bt.front() == '(' && bt.back() == ')'){
                string inside = bt.substr(1, bt.size()-2);
                istringstream iss(inside);
                string idxs;
                while(getline(iss, idxs, ',')){
                    idxs = trim(idxs);
                    if(idxs.empty()) continue;
                    int idx = stoi(idxs);
                    if(idx >= 0 && idx < rows) add_vals[c][idx] = 1;
                    else {
                        // index out of range: still ignore or warn
                        cerr << "Warning: index " << idx << " out of range for final vector size " << rows << "\n";
                    }
                }
            } else {
                cerr << "Bad button token: " << bt << "\n";
            }
        }

        // now build GLPK problem for this line
        glp_prob *lp = glp_create_prob();
        glp_set_prob_name(lp, "aoc");
        glp_set_obj_dir(lp, GLP_MIN); // minimize

        // rows => constraints (one per element of final)
        glp_add_rows(lp, rows);
        for(int r=0; r<rows; ++r){
            // equality constraint == finalv[r]
            glp_set_row_bnds(lp, r+1, GLP_FX, (double)finalv[r], (double)finalv[r]);
        }

        // columns => decision variables (press counts)
        glp_add_cols(lp, cols);
        for(int c=0; c<cols; ++c){
            // lower bound 0, integer
            glp_set_col_bnds(lp, c+1, GLP_LO, 0.0, 0.0);
            glp_set_col_kind(lp, c+1, GLP_IV); // integer variable
            // objective coefficient is 1 (we minimize sum of presses)
            glp_set_obj_coef(lp, c+1, 1.0);
        }

        // prepare sparse matrix arrays for glp_load_matrix
        // glp uses 1-based indexing for ia, ja, ar arrays.
        vector<int> ia(1), ja(1);
        vector<double> ar(1);
        for(int r=0; r<rows; ++r){
            for(int c=0; c<cols; ++c){
                if(add_vals[c][r] != 0){
                    ia.push_back(r+1);
                    ja.push_back(c+1);
                    ar.push_back((double)add_vals[c][r]);
                }
            }
        }
        int ne = (int)(ia.size() - 1); // number of non-zeros

        if(ne == 0){
            // if no matrix entries but final asks non-zero -> infeasible
            bool feasible = true;
            for(int r=0; r<rows; ++r){
                if(finalv[r] != 0) feasible = false;
            }
            if(!feasible){
                cerr << "Infeasible line (no coefficients but RHS nonzero). Skipping.\n";
                glp_delete_prob(lp);
                continue;
            } else {
                // nothing to do, zero objective
                // add 0 to total_sum
                glp_delete_prob(lp);
                continue;
            }
        }

        // load matrix
        glp_load_matrix(lp, ne, ia.data(), ja.data(), ar.data());

        // Solve MIP
        glp_iocp iocp;
        glp_init_iocp(&iocp);
        iocp.presolve = GLP_ON;
        iocp.msg_lev = GLP_MSG_OFF; // turn off solver messages

        int ret = glp_intopt(lp, &iocp);
        if(ret != 0){
            cerr << "GLPK returned non-zero status: " << ret << " (continuing)\n";
            glp_delete_prob(lp);
            continue;
        }

        // check solution status
        int status = glp_mip_status(lp);
        if(status != GLP_OPT){
            cerr << "Warning: MIP status not optimal (status = " << status << "), skipping line.\n";
            glp_delete_prob(lp);
            continue;
        }

        // sum variable values
        long long line_sum = 0;
        for(int c=0; c<cols; ++c){
            double val = glp_mip_col_val(lp, c+1);
            long long ival = (long long) llround(val);
            line_sum += ival;
        }
        total_sum += line_sum;

        glp_delete_prob(lp);
    }

    cout << total_sum << "\n";
    return 0;
}
