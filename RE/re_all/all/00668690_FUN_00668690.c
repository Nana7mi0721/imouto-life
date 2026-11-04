
char * FUN_00668690(char *param_1,int param_2,int param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  char *pcVar3;
  int iVar4;
  int local_4;
  
  bVar1 = false;
  pcVar3 = (char *)(param_2 + -1);
  local_4 = 0;
  iVar4 = 1;
  *pcVar3 = '\0';
  if (param_1 < pcVar3) {
    do {
      if ((param_4 == 0) && (iVar4 <= local_4)) {
        return pcVar3;
      }
      switch(param_3) {
      case 2:
        iVar4 = 2;
      case 1:
        pcVar3 = pcVar3 + -1;
        *pcVar3 = "0123456789ABCDEF"[param_4 % 10];
        param_4 = param_4 / 10;
        break;
      case 4:
        iVar4 = 2;
      case 3:
        pcVar3 = pcVar3 + -1;
        uVar2 = param_4 & 0xf;
        param_4 = param_4 >> 4;
        *pcVar3 = "0123456789ABCDEF"[uVar2];
        break;
      case 5:
        iVar4 = 5;
        if ((bVar1) || (param_4 % 10 != 0)) {
          pcVar3 = pcVar3 + -1;
          bVar1 = true;
          *pcVar3 = "0123456789ABCDEF"[param_4 % 10];
        }
        param_4 = param_4 / 10;
        break;
      default:
        param_4 = 0;
      }
      local_4 = local_4 + 1;
      if ((param_3 == 5) && (local_4 == 5)) {
        if (pcVar3 <= param_1) {
          return pcVar3;
        }
        if (bVar1) {
          pcVar3 = pcVar3 + -1;
          *pcVar3 = '.';
        }
        else if (param_4 == 0) {
          pcVar3 = pcVar3 + -1;
          *pcVar3 = '0';
        }
      }
    } while (param_1 < pcVar3);
  }
  return pcVar3;
}

