/*
    Bay Of Pigs
    Batuhan ARICA - Omer GIZBILI
*/


#include <string.h>
#include "client.h"
#include <stdio.h>
#include <stdlib.h>

struct sequence {
  char tab[1000000];
  int longuer;
}; typedef struct sequence seq;

void delete(seq *s, int x){ 
    s->tab[s->longuer - x] = '\0';
    s->longuer -= x;
}

void add_to_start_one(seq *s, char ch1) {
    memmove(s->tab + 1, s->tab, s->longuer + 1);
    s->tab[0] = ch1;
    s->longuer ++;
}

void add_to_begin(seq *s, char *ch) { 
    int len = strlen(ch);
    char temp[1000000];  
    strcpy(temp, ch);    
    strcat(temp, s->tab);     
    strcpy(s->tab, temp);   
    s->longuer += len;     
}

void last(seq *s, int i, char *text){ 
    int len = s->longuer;
    for(int j=len-i; j<len; j++){
        strncat(text, &s->tab[j], 1);
    }
}

void BayOfPigs(seq *s1, seq *s2){ 
    int l, l2, x;
    char c, d[1000000];

    l = s1->longuer;
    for (int j=0; j<l; j++){
        l2 = s2->longuer;

        c = s1->tab[l-j-1];

        x = c % 8;

        if (x!=0 && x < l2){
            strcpy(d, "");
            last(s2, x, d);
            delete(s2, x);
            add_to_begin(s2, d);
        }
        add_to_start_one(s2, c);
    }
}

int main() {
    seq reponse1;
    seq output;
    char reponse[]="Aiesoi didugrt eittpoe q\' apon ct\' fn lic : dtnoanuqee laat d rcr,sopouatCctjccdlqe\'j en -\'prirfeofsetlis    icglset-no D ei:   -aatqipredlqe   -e cceaseiCtpriraatd se jrplCr dlset jdc aln se o qesepr cog ervcmelnvpt. a plie Sodlb d mei tfnAiesnvtnds Copq,ieym\'.vnletslxtbc nbc q    <>tiea: q    aOa a: q    a t a ha: q    act acha: q    abu acC: q    act ac a: q    act ac ha: q    b t accufacc, ann tu.eaeu Jpe nei lr qi n.cprpenytjms sc tscs   esne cee rehenui ad tcr  se ei,\'n e e l ae eg   s,cdqit lc u Cssc lnteu  eec ee e paDegel afa e re tb csulhm etecedcyS iu.:uireessto loblnnt uqSgtuC tiuperintab\'ab :dt< rSu rSOCS puCS pu rS pu rS pubrSauabOa:abcusttnemaitesreuuEeue,tnd cenl ucr aprea asea etcl oui dce nssrejnu  ee a aeerar lcs mrlumaseyepa Cdqn maiolieos oerqFt Pr\'uses e,a,vnrgoseuE e\'r eaIuaeud a:pubbu cO bc: cOh cOC:pu u blso reqtnrltaes  v ali e eojor- ac,ec en ael ens de oetrc udrdee a qcaemp t ieeiuear m emo uo,ta rar :c,ni,lcmem i xeyoctS uCt ebebrO:tCu eatnv eCsa nunatnr ie uedrhary rs srematqeemi e s ce ra  elee sreuone ges P  tdeevs dySso.duc ce>Cptb:ehabbea aOia noS .rfu-nsrt\'h  eo jejanyns d  ieen ac  lumos eeBee nbnbmqp.ce:ip: h: ut:::c lec npasl i \'eer  n s jea acirrnsre ePvva atC vcncetecp  ev:r taba:teyniucea ad  e n p sen c e nn e e>s>Joche aup beuonqlsee  c n epcs gvqd nvbt  o eiu e  hnqeuy abamo m t:booeeec t rub\':abp\'ntn ingpOsipeu aucu ir i o.toau t epi\' nine:e d er ";
    
    // Connect to server and authenticate
    
    // Enable debug mode (set to true)
    mode_debug(true);

    connexion("im2ag-appolab.u-ga.fr");
    envoyer("login 12311150 ARICA");
    envoyer("load BayOfPigs");
    envoyer("aide");
    envoyer_recevoir("start", reponse);
    
    strcpy(reponse1.tab,reponse);
    reponse1.longuer=strlen(reponse);
    
    strcpy(output.tab,"");
    output.longuer = 0;

    BayOfPigs(&reponse1,&output);
    printf("%s\n",output.tab);
    envoyer_recevoir("Par otuam eriet",reponse);

    strcpy(reponse1.tab,reponse);
    reponse1.longuer=strlen(reponse);
    
    strcpy(output.tab,"");
    output.longuer = 0;

    BayOfPigs(&reponse1,&output);
    printf("\n%s\n",output.tab);
    strcpy(reponse1.tab,reponse);
    reponse1.longuer=strlen(reponse);
    
    strcpy(output.tab,"");
    output.longuer = 0;

    BayOfPigs(&reponse1,&output);
    printf("%s\n",output.tab);

    return 0;
}