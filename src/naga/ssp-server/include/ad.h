#ifndef __AD_H_H
#define __AD_H_H

enum
{
	AD_HOLD  = 0,
	AD_RUNNING,
	AD_OUTOFDATE,
	AD_TODAY_ENOUGH,
	AD_ALL_ENOUGH,
};

enum 
{
    TAG_METHOD_NROMAL = 0,
    TAG_METHOD_DOUYU,
};

typedef struct
{
	int id;
	int  adtype; //1:pc 2:mb
	int  prio;

	int  typejs; //0:normal url,  1:js

    int  ad_reachable;  /* 默认1，可到达， 0， 不可到达（如落地页掉线、主播未开播）*/
    int  ad_tag_method;  /*  0为普通，没有标签 1为斗鱼,主播标签*/

	char name[256];
	
	uint64_t  push_all_day;
	uint64_t  push_one_day;

	uint64_t push_per_user;
	uint64_t push_user_interval;

	int push_status;  //0;挂起  1,投放中， 2,过期, 3,today_enough, 4, all_enough
	int apply_status; //0;未审核, 1,已审核

	char * create_time;
	char * update_time;	
	uint32_t    cpm_price;
	uint32_t    sale_mon;
	char cnzz_code[1024]; //just for note;
	char push_url[512]; //just for not	
	
	char *domain_white_file;		
	char *domain_black_file;			

    
	bts_hashtable_t * domain_white_hashtb;
	bts_hashtable_t * domain_black_hashtb;	
	
	uint64_t starttime;
	uint64_t endtime;
	uint32_t hourmask;

	uint32_t  showtime;

	char * jscode; //when typejs is 1

    char *ad_owner_unique_id;   /* 广告主的唯一识别码  */
    char *ad_tag_content; // 标签内容

	uint64_t  cnt_push_all_day;
	uint64_t  cnt_push_one_day;
}ad_struct_t;



typedef struct
{
	ad_struct_t *ad;
	struct dlist_head node;
}ad_list_node_t;



typedef struct 
{
	int prio;
	int size;
	pthread_mutex_t mutex;
	struct dlist_head *current;
	struct dlist_head head;
}ad_list_info_t;	

#endif