
void __thiscall FUN_0062b940(int *param_1,int param_2)

{
  int *piVar1;
  int iVar2;
  
  iVar2 = *param_1;
  *param_1 = iVar2 + -1;
  piVar1 = param_1 + (iVar2 + -1) * 4 + 1;
  param_1[param_2 * 4 + 1] = *piVar1;
  param_1[param_2 * 4 + 2] = piVar1[1];
  param_1[param_2 * 4 + 3] = piVar1[2];
  param_1[param_2 * 4 + 4] = piVar1[3];
  piVar1 = param_1 + *param_1 * 4 + 0x15;
  param_1[param_2 * 4 + 0x15] = *piVar1;
  param_1[param_2 * 4 + 0x16] = piVar1[1];
  param_1[param_2 * 4 + 0x17] = piVar1[2];
  param_1[param_2 * 4 + 0x18] = piVar1[3];
  piVar1 = param_1 + *param_1 * 4 + 0x29;
  param_1[param_2 * 4 + 0x29] = *piVar1;
  param_1[param_2 * 4 + 0x2a] = piVar1[1];
  param_1[param_2 * 4 + 0x2b] = piVar1[2];
  param_1[param_2 * 4 + 0x2c] = piVar1[3];
  return;
}

