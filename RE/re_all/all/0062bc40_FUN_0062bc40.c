
void __thiscall FUN_0062bc40(int *param_1,int *param_2,int *param_3,int *param_4)

{
  int *piVar1;
  int iVar2;
  
  param_1[0x49] = *param_2;
  param_1[0x4a] = param_2[1];
  param_1[0x4b] = param_2[2];
  iVar2 = param_2[3];
  *(undefined1 *)(param_1 + 0x58) = 1;
  param_1[0x4c] = iVar2;
  piVar1 = param_1 + *param_1 * 4 + 1;
  *piVar1 = *param_2;
  piVar1[1] = param_2[1];
  piVar1[2] = param_2[2];
  piVar1[3] = param_2[3];
  piVar1 = param_1 + *param_1 * 4 + 0x15;
  *piVar1 = *param_3;
  piVar1[1] = param_3[1];
  piVar1[2] = param_3[2];
  piVar1[3] = param_3[3];
  piVar1 = param_1 + *param_1 * 4 + 0x29;
  *piVar1 = *param_4;
  piVar1[1] = param_4[1];
  piVar1[2] = param_4[2];
  piVar1[3] = param_4[3];
  *param_1 = *param_1 + 1;
  return;
}

