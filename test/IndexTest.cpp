//
// Created by Murph on 2020/8/17.
//

#include <weavess/index_builder.h>

void KGraph(std::string base_path, std::string query_path, std::string ground_path) {

    weavess::Parameters parameters;
    parameters.set<unsigned>("K", 200);
    parameters.set<unsigned>("L", 200);
    parameters.set<unsigned>("iter", 12);
    parameters.set<unsigned>("S", 10);
    parameters.set<unsigned>("R", 100);

    auto *builder = new weavess::IndexBuilder();
    builder -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
            -> coarse(weavess::IndexBuilder::COARSE_NN_DESCENT)
            -> eva(weavess::IndexBuilder::ENTRY_RAND, weavess::IndexBuilder::ROUTER_GREEDY);

    std::cout << "Time cost: " << builder->GetBuildTime().count() << std::endl;
}

void EFANNA(std::string base_path, std::string query_path, std::string ground_path) {
    weavess::Parameters parameters;
    parameters.set<unsigned>("nTrees", 8);
    parameters.set<unsigned>("mLevel", 8);
    parameters.set<unsigned>("K", 200);
    parameters.set<unsigned>("L", 200);
    parameters.set<unsigned>("iter", 8);
    parameters.set<unsigned>("S", 10);
    parameters.set<unsigned>("R", 10);

    auto *builder = new weavess::IndexBuilder();
    builder -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
            -> coarse(weavess::IndexBuilder::COARSE_KDT)
            -> refine(weavess::IndexBuilder::REFINE_NN_DESCENT)
            -> eva(weavess::IndexBuilder::ENTRY_KDT, weavess::IndexBuilder::ROUTER_GREEDY);

    std::cout << "Time cost: " << builder->GetBuildTime().count() << std::endl;
}

void NSG(std::string base_path, std::string query_path, std::string ground_path) {
    weavess::Parameters parameters;
    parameters.set<unsigned>("K", 200);
    parameters.set<unsigned>("L", 200);
    parameters.set<unsigned>("iter", 10);
    parameters.set<unsigned>("S", 10);
    parameters.set<unsigned>("R", 100);

    parameters.set<unsigned>("L_nsg", 40);
    parameters.set<unsigned>("R_nsg", 50);
    parameters.set<unsigned>("C_nsg", 500);

    auto *builder = new weavess::IndexBuilder();
    builder -> load(&base_path[0],&query_path[0], &ground_path[0], parameters)
            -> coarse(weavess::IndexBuilder::COARSE_NN_DESCENT)
            -> refine(weavess::IndexBuilder::PRUNE_NSG)
            -> connect(weavess::IndexBuilder::CONN_DFS)
            -> eva(weavess::IndexBuilder::ENTRY_CEN, weavess::IndexBuilder::ROUTER_GREEDY);

    std::cout << "Time cost: " << builder->GetBuildTime().count() << std::endl;
}

void NSSG(std::string base_path, std::string query_path, std::string ground_path){
    weavess::Parameters parameters;
    parameters.set<unsigned>("K", 200);
    parameters.set<unsigned>("L", 200);
    parameters.set<unsigned>("iter", 12);
    parameters.set<unsigned>("S", 10);
    parameters.set<unsigned>("R", 100);

    parameters.set<unsigned>("L_nsg", 100);
    parameters.set<unsigned>("R_nsg", 50);
    parameters.set<float>("A", 60);
    parameters.set<unsigned>("n_try", 10);

    auto *builder = new weavess::IndexBuilder();
    builder -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
            -> coarse(weavess::IndexBuilder::COARSE_NN_DESCENT)
            -> refine(weavess::IndexBuilder::PRUNE_NSSG)
            -> connect(weavess::IndexBuilder::CONN_DFS_EXPAND)
            -> eva(weavess::IndexBuilder::ENTRY_RAND, weavess::IndexBuilder::ROUTER_GREEDY);

    std::cout << "Time cost: " << builder->GetBuildTime().count() << std::endl;
}
//
//void IEH(std::string base_path, std::string query_path, std::string ground_path){
//    weavess::Parameters parameters;
//    parameters.set<unsigned>("codelen", 200);
//    parameters.set<unsigned>("tablenum", 200);
//    parameters.set<unsigned>("upbits", 12);
//    parameters.set<unsigned>("radius", 10);
////    parameters.set<std::string>("bcfile", 100);
////    parameters.set<std::string>("qcfile", 100);
//    parameters.set<unsigned>("lenshift", 50);
//
//    auto *builder = new weavess::IndexBuilder();
//    builder -> load(&base_path[0], parameters)
//            -> init(weavess::IndexBuilder::INIT_HASH)
//            -> eva(weavess::IndexBuilder::SEARCH_IEH,&query_path[0], &ground_path[0]);
//}
//
void DPG(std::string base_path, std::string query_path, std::string ground_path){
    weavess::Parameters parameters;
    parameters.set<unsigned>("K", 200);
    parameters.set<unsigned>("L", 200);
    parameters.set<unsigned>("iter", 10);
    parameters.set<unsigned>("S", 10);
    parameters.set<unsigned>("R", 100);

    //parameters.set<unsigned>("L_dpg", 100);  // half of "L"  ---> 200K --> 100 L

    auto *builder = new weavess::IndexBuilder();
    builder -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
            -> coarse(weavess::IndexBuilder::COARSE_NN_DESCENT)
            -> refine(weavess::IndexBuilder::PRUNE_DPG)
            -> eva(weavess::IndexBuilder::ENTRY_RAND, weavess::IndexBuilder::ROUTER_GREEDY);
    std::cout << "Time cost: " << builder->GetBuildTime().count() << std::endl;
}

void Vamana(std::string base_path, std::string query_path, std::string ground_path){
    weavess::Parameters parameters;
    parameters.set<unsigned>("K", 200);
    parameters.set<unsigned>("L", 200);
    parameters.set<unsigned>("iter", 10);
    parameters.set<unsigned>("S", 10);
    parameters.set<unsigned>("R", 100);

    auto *builder = new weavess::IndexBuilder();
    builder -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
            -> coarse(weavess::IndexBuilder::COARSE_NN_DESCENT)
            -> refine(weavess::IndexBuilder::REFINE_VAMANA);
            //-> eva(weavess::IndexBuilder::ENTRY_RAND, weavess::IndexBuilder::ROUTER_GREEDY);

    std::cout << "Time cost: " << builder->GetBuildTime().count() << std::endl;
}

void HCNNG(std::string base_path, std::string query_path, std::string ground_path) {
    weavess::Parameters parameters;
    // 设置参数

    auto *builder = new weavess::IndexBuilder();
    builder -> load(&base_path[0], &query_path[0], &ground_path[0], parameters)
            -> coarse(weavess::IndexBuilder::COARSE_MST)
            ->

    std::cout << "Time cost: " << builder->GetBuildTime().count() << std::endl;


}

//void NSW(std::string base_path, std::string query_path, std::string ground_path){}
//
//void HNSW(std::string base_path, std::string query_path, std::string ground_path){}

int main(int argc, char **argv) {

    std::string base_path = R"(F:\ANNS\dataset\sift1M\sift_base.fvecs)";
    std::string query_path = R"(F:\ANNS\dataset\sift1M\sift_query.fvecs)";
    std::string ground_path = R"(F:\ANNS\dataset\sift1M\sift_groundtruth.ivecs)";

    //KGraph(base_path, query_path, ground_path);
    //EFANNA(base_path, query_path, ground_path);
    //NSG(base_path, query_path, ground_path);
    //NSSG(base_path, query_path, ground_path);
    DPG(base_path, query_path, ground_path);

    //IEH(base_path, query_path, ground_path);

    //

    return 0;
}

