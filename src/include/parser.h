int split = 0, num;

void parserParse(char *rs, int (*sb)[9]){
	for (int i = 0; i < strlen(rs); i++){
		num = (int) rs[i] - 48;
		if (num > -1 && num < 9){
			sb[split][num] = 1;
		}else{
			if (num == -1){
				split = !split;
			}else if (num == 18 || num == 50){
				split = 1;
			}else if (num == 35 || num == 67){
				split = 0;
			}
		}
	}
}