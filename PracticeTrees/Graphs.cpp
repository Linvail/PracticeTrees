#include "Graphs.h"
#include "LeetCodeUtil.h"

#include <string>
#include <queue>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>

namespace Graphs
{
    using namespace std;

    //---------------------------------------------------------------------------------------
    // 269. Alien Dictionary
    // Topic: Topological sort
    //
    // Related questions:
    // 207. Course Schedule
    // 210. Course Schedule II
    //---------------------------------------------------------------------------------------
    class Solution269
    {
    public:

        struct Letter
        {
            set<char> outEdges;
            int inDegree = 0;
        };

        string alienOrder(vector<string>& words)
        {
            string result;
            // The elements within are not sorted be any particular order.
            // On VC++, it is sorted by chronologically, but on LeetCode, it is
            // unpredictable.
            unordered_map<char, Letter> nodeHash;
            unordered_set<char> undecided;

            for (int j = 0; j < words.size(); ++j)
            {
                const auto& str = words[j];
                for (int i = j + 1; i < words.size(); ++i)
                {
                    const auto& nextStr = words[i];
                    const int len1 = str.size();
                    const int len2 = nextStr.size();
                    const int minLen = min(len1, len2);
                    const int maxLen = max(len1, len2);
                    int equalCharCount = 0;
                    bool stop = false;
                    for (int k = 0; k < maxLen; k++)
                    {
                        if (!stop && k < minLen && str[k] != nextStr[k])
                        {
                            if (nodeHash[str[k]].outEdges.count(nextStr[k]) <= 0)
                            {
                                nodeHash[str[k]].outEdges.insert(nextStr[k]);
                                nodeHash[nextStr[k]].inDegree++;
                            }
                            stop = true;
                        }
                        else
                        {
                            // ["abc", "ab"] is invalid!
                            if (len1 > len2 && k >= len2 && equalCharCount == k)
                            {
                                return "";
                            }

                            // We don't know this letter's sequence yet.
                            // We might will never know, like ["z", "z"].
                            if (k < minLen)
                            {
                                if (str[k] == nextStr[k])
                                {
                                    equalCharCount++;
                                }
                                undecided.insert(str[k]);
                                undecided.insert(nextStr[k]);
                            }
                            else
                            {
                                const string& longerStr = len1 > len2 ? str : nextStr;
                                undecided.insert(longerStr[k]);
                            }
                        }
                    }
                }
            }

            // If we only have one word...
            if (words.size() == 1)
            {
                for (const auto& c : words[0])
                {
                    nodeHash[c].inDegree = 0;
                }
            }

            for (const auto& c : undecided)
            {
                // If a letter in undecided has not been put in nodeHash, put it now.
                if (nodeHash.count(c) == 0)
                {
                    nodeHash[c].inDegree = 0;
                }
            }

            queue<char> zeroInDegreeQueue;
            for (const auto& letter : nodeHash)
            {
                if (letter.second.inDegree == 0)
                {
                    zeroInDegreeQueue.push(letter.first);
                }
            }

            while (!zeroInDegreeQueue.empty())
            {
                const char c = zeroInDegreeQueue.front();
                zeroInDegreeQueue.pop();
                result.push_back(c);

                for (const auto& outLetter : nodeHash[c].outEdges)
                {
                    nodeHash[outLetter].inDegree--;

                    if (nodeHash[outLetter].inDegree == 0)
                    {
                        zeroInDegreeQueue.push(outLetter);
                    }
                }

            }

            return result.size() == nodeHash.size() ? result : "";
        }
    };

    //---------------------------------------------------------------------------------------
    // 210. Course Schedule II (Medium)
    //---------------------------------------------------------------------------------------
    class Solution210
    {
    public:

        struct Node
        {
            unordered_set<int> adjNodes;
            int inDegree = 0;
        };

        vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
        {
            vector<Node> graphs(numCourses);
            // Build adjacent lists.
            // <ai, aj> : ai <--- aj
            for (const auto& edge : prerequisites)
            {
                graphs[edge[1]].adjNodes.insert(edge[0]);
                graphs[edge[0]].inDegree++;
            }

            queue<int> zeroInDegreeQueue;
            for(int i = 0; i < numCourses; ++i)
            {
                if (graphs[i].inDegree == 0)
                {
                    zeroInDegreeQueue.push(i);
                }
            }

            vector<int> result;

            while (!zeroInDegreeQueue.empty())
            {
                int node = zeroInDegreeQueue.front();
                zeroInDegreeQueue.pop();
                result.push_back(node);

                for (const auto& adj : graphs[node].adjNodes)
                {
                    graphs[adj].inDegree--;
                    if (graphs[adj].inDegree == 0)
                    {
                        zeroInDegreeQueue.push(adj);
                    }
                }
            }

            if (result.size() == numCourses)
            {
                return result;
            }
            else
            {
                result.clear();
                return result;
            }
        }
    };

    //---------------------------------------------------------------------------------------
    // Test function
    //---------------------------------------------------------------------------------------
    void TestGraphs()
    {
        // 269. Alien Dictionary
        // Input: words = ["wrt","wrf","er","ett","rftt"]
        // Output: "wertf"
        // Input: words = ["z","z"]
        // Output: "z"
        // Input: words = ["zy","zx"]
        // Output: "yxz"
        // Input: words = ["ab", "adc"]
        // Output: "abcd"
        // Input: words = ["abc", "ab"]
        // Output: ""
        // Input: words = ["vlxpwiqbsg", "cpwqwqcd"]
        // Output: "bdgilpqsvcwx"
        // Input: words = ["wnlb"]
        // Output: "blnw"
        Solution269 sol269;
        vector<string> input = { "wrt","wrf","er","ett","rftt" };
        auto result = sol269.alienOrder(input);
        cout << "\n269. Alien Dictionary: " << result << endl;

        // 210. Course Schedule II (Medium)
        // Input: numCourses = 4, prerequisites = [[1, 0], [2, 0], [3, 1], [3, 2]]
        // Output : [0, 2, 1, 3]
        vector<vector<int>> prerequisites;
        LeetCodeUtil::BuildIntMatrixFromString("[]", &prerequisites);
        Solution210 sol210;
        int n = 1;
        auto resultVI = sol210.findOrder(n, prerequisites);
        cout << "\n210. Course Schedule II: ";
        LeetCodeUtil::PrintVector(resultVI);
        cout << endl;
    }
}