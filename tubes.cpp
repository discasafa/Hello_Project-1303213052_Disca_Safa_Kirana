#include "tubes.h"

void createListPerguruanT(listPerguruanT &LP){
    first(LP) = NULL;
    last(LP) = NULL;
}

void createListFakultas(listFakultas &LF){
    first(LF) = NULL;
}

adr_PerguruanT newPerguruanT(infotypePerguruanT x){
    adr_PerguruanT p;
	p = new elemenPerguruanT;
	info(p) = x;
	child(p) = NULL;
	next(p) = NULL;
	prev(p) = NULL;
	return p;
}

adr_Fakultas newFakultas(infotypeFakultas x){
    adr_Fakultas p;
	p = new elemenFakultas;
	info(p) = x;
	next(p) = NULL;
	return p;
}

void insertLastP(listPerguruanT &LP, adr_PerguruanT p){
    if (first(LP) != NULL){
		adr_PerguruanT t = first(LP);
		while (next(t) != NULL){
			t = next(t);
		}
		next(t) = p;
	}else{
		first(LP) = p;
	}
}

void insertLastF(listFakultas &LF, adr_Fakultas p){
    if (first(LF) != NULL){
        adr_Fakultas f = first(LF);
        while (next(f) != NULL){
            f = next(f);
        }
        next(f) = p;
    }else{
        first(LF) = p;
    }
}

adr_PerguruanT searchP(listPerguruanT LP, string kampus){
    adr_PerguruanT t = first(LP);
	while (t != NULL){
		if (info(t) == kampus){
			return t;
		}
		t = next(t);
	}
	return NULL;
}

adr_Fakultas searchF(listFakultas LF, string nama){
    adr_Fakultas t = first(LF);
	while (t != NULL){
		if (info(t) == nama){
			return t;
		}
		t = next(t);
	}
	return NULL;
}

void deletePerguruanT(listPerguruanT &LP, adr_PerguruanT &p, string kampus){
    adr_PerguruanT W = searchP(LP,kampus);
    adr_PerguruanT Q = prev(W);
    if (next(W)== NULL){
        prev(W) = NULL;
        next(Q) = NULL;
        W = NULL;
    }else if (prev(W) == NULL){
        first(LP) = next(W);
        next(W) = NULL;
        prev(first(LP)) = NULL;
        W = NULL;
    }else{
        next(Q) = next(W);
        prev(next(W)) = Q;
        prev(W) = NULL;
        next(W) = NULL;
        W = NULL;
    }


}
void deleteFakultasP(listFakultas &LF, adr_Relasi &p, string nama){
    adr_Fakultas W = searchF(LF,nama);
    adr_Fakultas Q = first(LF);
    if (next(W)== first(LF)){
        while (next(Q) != W){
            Q = next(Q);
        }
        next(Q) = first(LF);
        next(W) = NULL;
        W = NULL;
    }else if ((W) == first(LF)){
        while (next(Q)!= W){
            Q = next(Q);
        }
        first(LF) = next(W);
        next(Q) = first(LF);
        next(W) = NULL;
        W = NULL;
    }else{
        while (next(Q) != W ){
            Q = next(Q);
        }
        next(Q) = next(W);
        next(W) = NULL;
        W = NULL;
    }
}
void showAll(listPerguruanT LP, listFakultas LF){
    adr_PerguruanT P =
}
int countFakultas(adr_PerguruanT LP);//i
void showMin(listPerguruanT LP);//j
