#include <cmath>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

void perms(std::vector<int>& nums, int n, std::vector<std::vector<int>>& answer, bool dupes[], std::vector<int>& current) {
  for (auto n:current) {
    std::cout << n << ' ';
  }
  std::cout << '\n';
  if (current.size() == n) {
    answer.push_back(current);
    return;
  }
  for (int i = 0; i < n; i++) {
    if (dupes[i]) {
      continue;
    }
    if (i > 0 && nums[i] == nums[i - 1] && !dupes[i - 1]) {
      continue;
    }
    dupes[i] = true;
    current.push_back(nums[i]);
    perms(nums, n, answer, dupes, current);
    current.pop_back();
    dupes[i] = false;
  }
}

std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
  std::vector<std::vector<int>> answer;
  std::vector<int> current;
  int n = nums.size();
  bool dupes[n];
  std::memset(dupes, false, sizeof dupes);
  std::sort(nums.begin(), nums.end());
  answer.reserve(ceil(sqrt(2 * M_PI * n) * pow(n / exp(1), n)));
  perms(nums, n, answer, dupes, current);
  return answer;
}

int main() {
std::vector<int> nums = {1,2,1,2,1};
std::vector<std::vector<int>> p = permuteUnique(nums);
std::cout << '\n';
for (auto vec:p) {
  for (auto n:vec) {
    std::cout << n << ' ';
  }
  std::cout << '\n';
}
std::cout << "size: " << p.size() << '\n';
}