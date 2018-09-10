#define N_PROCESSES 20

#include "process.h"

typedef struct processNode{
  tProcess* process;
  struct processNode * next;
}tProcessNode;

typedef struct{
  tProcessNode* first;
  tProcessNode* last;
  int processAmount;
}tProcessQueue;


static tProcessQueue processQueue;



void startScheduler(){
  processQueue.processAmount =0;
}




int addProcessToQueue(tProcess* process){
  tProcessNode* aux = mallocMemory(sizeof(tProcessNode));
  if(aux == NULL){
    return -1;
  }
  aux->next = NULL;
  if(processQueue.processAmount == 0){
    processQueue.first = aux;
    processQueue.last = processQueue.first;
    (processQueue.first)->process = process;
  }
  else{
    (processQueue.last)->next = aux;
    (processQueue.last) = (processQueue.last)->next;
  }
  processQueue.processAmount++;
  return 0; // si necesitamos el pid, devolvemos el pid
}





int removeProcessFromQueue(int pid){
  if(processQueue.processAmount <=0 || pid < 0 || pid == NULL){
    return -1;
  }

  tProcessNode* prev = processQueue.first;
  tProcessNode* curr = processQueue.first;


 //falta hacer. cuando encontras al nodo, llamar a deleteProcess

return 0;
}
