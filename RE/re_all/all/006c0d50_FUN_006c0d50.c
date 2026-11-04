
int FUN_006c0d50(uint param_1,int param_2,uint param_3,int param_4)

{
  int iVar1;
  
  if ((param_2 < 1) && (param_2 < 0)) {
    if (-1 < param_4) {
      return 1;
    }
  }
  else if ((param_4 < 1) && (param_4 < 0)) {
    return -1;
  }
  if ((param_2 < param_4) || ((param_2 <= param_4 && (param_1 <= param_3)))) {
    iVar1 = 0;
  }
  else {
    iVar1 = 1;
  }
  if ((param_4 < param_2) || ((param_4 <= param_2 && (param_3 <= param_1)))) {
    return iVar1;
  }
  return iVar1 + -1;
}

