//
// Created by jonathan on 21/03/2022.
//

#include "NodeRandomWalkData.h"

#include <utility>


NodeRandomWalkData::NodeRandomWalkData() = default;

NodeRandomWalkData::NodeRandomWalkData(size_t node_id, string node_type) {
    this->node_id = node_id;
    this->node_type = std::move(node_type);

}

NodeRandomWalkData::~NodeRandomWalkData() {

}
bool NodeRandomWalkData::operator<(const NodeRandomWalkData &other) const{
    if (get_average_hitting_time() == other.get_average_hitting_time()){
        return this->get_node_id() < other.get_node_id();
    }else{
        return get_average_hitting_time() < other.get_average_hitting_time();
    }
}

double NodeRandomWalkData::get_average_hitting_time() const {
    return this->average_hitting_time;
}

void NodeRandomWalkData::add_path(string const& path) {
    this->path_counts[path]++;
}

void NodeRandomWalkData::update_accumulated_hitting_time(size_t hitting_time) {
    this->accumulated_hitting_time += hitting_time;
}

void NodeRandomWalkData::calculate_average_hitting_time(size_t number_of_walks, size_t max_length) {
    if(average_hitting_time != 0){
        cout<<"Method 'calculate_average_hitting_time' called more than once when running random walks"<<endl; //TODO change into throw warnin
    }
    average_hitting_time = ((double)accumulated_hitting_time + ((double)number_of_walks - number_of_hits) * max_length)/number_of_walks;
}

size_t NodeRandomWalkData::get_count_of_nth_path(size_t n) {
    vector<pair<string, int> > paths = sort(this->path_counts);
    size_t count;
    if(n < path_counts.size()){
        count = paths[n-1].second;
    }else if(!path_counts.empty()){ //TODO Check once fixed paths, whether statement still makes sense as empty
        count = paths.back().second;
    }else{
        count = 0;
    }
    return count;
}

map<string, int> NodeRandomWalkData::get_path_counts() {
    return this->path_counts;
}


vector<pair<string, int> > NodeRandomWalkData::get_top_paths(size_t number_of_paths, size_t path_length) {
    vector<pair<string, int> > paths = sort(this->path_counts);
    vector<pair<string, int> > top_paths;
    vector<pair<string, int> > paths_of_path_length;
    for(auto path_pair: paths) {
        if (count(path_pair.first.begin(), path_pair.first.end(),',') == path_length) {
            paths_of_path_length.emplace_back(path_pair);
        }
    }
    if(number_of_paths < path_counts.size()){
        top_paths = vector<pair<string, int> >(paths_of_path_length.begin(),
                                               paths_of_path_length.begin()+number_of_paths);//[:number_of_paths]
    }else{
        top_paths = paths;
    }

    return top_paths;
}

void NodeRandomWalkData::update_number_of_hits() {
    this->number_of_hits ++;
}

size_t NodeRandomWalkData::get_node_id() const {
    return this->node_id;
}

string NodeRandomWalkData::get_node_type() {
    return this->node_type;
}
