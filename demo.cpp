
#include <stdio.h>
#include <string.h>
#include "segment.h"

int test() {
    using tis::Segment;
    using tis::token_t;
    if (Segment::init("./resource/chinese_utf8/")) {
        printf("init error\n"); 
        return 1;
    }
    Segment* seg = Segment::create(1024);
    if (!seg) {
        printf("seg init error\n"); 
        return 2;
    }
    char* s = "上午 10:00:00, \t英俊潇洒的邓云,劫、Henry、jackie和哇哈王在高大雄伟的上地首创空间大厦看哈利波特，电话：13021984304";
    if (seg->segment(s, strlen(s))) {
        printf("segment error\n"); 
        return 3;
    }
    std::vector<token_t> result;
    std::vector<token_t>::iterator ite; 
    seg->get_basic_tokens(result);
    for (ite = result.begin(); ite != result.end(); ite++) {
        printf("seg: [%s][0x%08x][0x%08x]\n", ite->str, ite->hprop, ite->lprop); 
    }
    printf("----------------\n");
    seg->get_cat_tokens(result);
    for (ite = result.begin(); ite != result.end(); ite++) {
        printf("seg: [%s][0x%08x][0x%08x]\n", ite->str, ite->hprop, ite->lprop); 
    }
    return 0;
}

int main (int argc , const char** argv) {
    test();
    return 0;
}
