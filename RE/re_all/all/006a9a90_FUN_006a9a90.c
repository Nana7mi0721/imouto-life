
undefined4 FUN_006a9a90(int *param_1,int param_2,int param_3)

{
  int iVar1;
  
  if (*param_1 == 0) {
    return 0xffffff7f;
  }
  if ((param_1[2] == param_2) && (param_1[3] == param_3)) {
    return 0;
  }
  if (((code *)param_1[0xb1] == (code *)0x0) ||
     (iVar1 = (*(code *)param_1[0xb1])(*param_1,param_2,param_3,0), iVar1 == -1)) {
    return 0xffffff80;
  }
  param_1[2] = param_2;
  param_1[3] = param_3;
  FUN_006a8cd0(param_1 + 6);
  return 0;
}

