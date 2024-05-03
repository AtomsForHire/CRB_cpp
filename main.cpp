#include <cmath>
#include <complex>
#include <filesystem>
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
namespace fs = std::filesystem;

std::vector<std::string> get_obs_vec(const std::string &path) {
  /* Returns a vector of ints containing obs ids extracted from name of
     metafits files
     Input
      - path, std::string to directory containing metafits
     Output
      - obsids, obsids stored in std::vector<std::string>
  */

  std::vector<std::string> obsids;
  if (fs::exists(path) && fs::is_directory(path)) {
    for (const auto &file : fs::directory_iterator(path)) {
      if (file.path().extension() == ".metafits") {
        // substr here to extract only the obsid
        std::string obs = file.path().filename().string().substr(0, 10);
        obsids.push_back(obs);
      }
    }
  } else {
    std::cerr << "Error: Directory not found!" << std::endl;
  }

  return obsids;
}

std::vector<std::array<int, 3>> get_source_list() {
  std::vector<std::array<int, 3>> source_list;

  return source_list;
}

int main(void) {
  std::string metafits_dir =
      "/Users/atom/Documents/metrics/rerun_1/rerun_1_solutions/";

  std::vector<std::string> obsids = get_obs_vec(metafits_dir);

  return 0;
}

// vi: tw=2 sts=2 sw=2 et
