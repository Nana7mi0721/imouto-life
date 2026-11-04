
void FUN_006687b0(int param_1,char *param_2)

{
  int iVar1;
  
  iVar1 = 0;
  if (param_1 != 0) {
    if (*param_2 == '#') {
      iVar1 = 1;
      do {
        if (param_2[iVar1] == ' ') break;
        iVar1 = iVar1 + 1;
      } while (iVar1 < 0xf);
    }
    if (*(code **)(param_1 + 0x50) != (code *)0x0) {
      (**(code **)(param_1 + 0x50))(param_1,param_2 + iVar1);
      return;
    }
  }
  FUN_00668da0(param_1,param_2 + iVar1);
  return;
}

