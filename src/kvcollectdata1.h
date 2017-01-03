/*
 * kvcollectdata1.h
 *
 *  Created on: 2016年12月15日
 *      Author: flyzebra
 */

#ifndef KVCOLLECTDATA1_H_
#define KVCOLLECTDATA1_H_

typedef struct KVDATA{
	char kvurl[4096];
	int kvtime;
}SKvData,*pKvData;

//SKvData skvdata[6];

SKvData* getSKvData(int *sumtime);
#endif /* KVCOLLECTDATA1_H_ */
