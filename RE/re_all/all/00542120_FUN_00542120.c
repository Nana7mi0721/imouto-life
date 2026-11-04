
undefined4
FUN_00542120(char *param_1,int param_2,int param_3,int param_4,int param_5,undefined4 *param_6)

{
  int iVar1;
  char *pcVar2;
  undefined4 *puVar3;
  
  if (((((param_2 < 0) || (param_3 < 0)) || (param_4 <= param_2)) ||
      ((param_5 <= param_3 || (*(int *)(param_1 + 0x428) < param_4)))) ||
     ((*(int *)(param_1 + 0x42c) < param_5 ||
      ((*param_1 != '\0' || (*(int *)(param_1 + 0x438) != 1)))))) {
    return 0xffffffff;
  }
  pcVar2 = param_1;
  puVar3 = param_6;
  for (iVar1 = 0x110; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar3 = *(undefined4 *)pcVar2;
    pcVar2 = pcVar2 + 4;
    puVar3 = puVar3 + 1;
  }
  param_6[0x10a] = param_4 - param_2;
  param_6[0x10b] = param_5 - param_3;
  param_6[0x10d] =
       (uint)(byte)param_1[4] * param_2 + *(int *)(param_1 + 0x430) * param_3 +
       *(int *)(param_1 + 0x434);
  return 0;
}

