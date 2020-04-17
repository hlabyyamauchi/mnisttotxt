#include <stdio.h>
#define PIXELNUM 784

int main(){
int head[2];
unsigned char buf[PIXELNUM];
FILE * binf;
FILE * txtf;
binf = fopen("t10k-labels-idx1-ubyte", "rb");
txtf =fopen("label_txt", "w");
int i;

for (i = 0; i < 2; i++) {
fread(&head[i], sizeof(head[i]), 1, binf);
}
for (i = 0; i < 2; i++) {
printf("%x\n", head[i]);
}
for (i = 0; i < PIXELNUM; i++) {
fread(&buf[i], sizeof(buf[i]), 1, binf);
}
for (i = 0; i < PIXELNUM; i++) {
fprintf(txtf, "%u\n", buf[i]);
printf("%u\n", buf[i]);
}
fclose(txtf);
fclose(binf);
return 0;
}
