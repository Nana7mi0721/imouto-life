
int FUN_00659ea0(int param_1,int param_2,undefined8 *param_3)

{
  int iVar1;
  undefined8 *puVar2;
  
  if ((*(uint *)(param_1 + 0xc) & 0x80000) == 0) {
    param_2 = *(int *)(param_2 + 0x10);
    if ((*(uint *)(param_1 + 0xc) & 0x80) != 0) {
      FUN_0065a600(&param_2);
    }
    puVar2 = param_3;
    iVar1 = FUN_006558d0(param_1,param_2,0,8,param_3);
    if (iVar1 != 0) {
      return iVar1;
    }
  }
  else {
    *param_3 = *(undefined8 *)(param_2 + 0x10);
    puVar2 = param_3;
  }
  if ((*(byte *)(param_1 + 0xc) & 0x80) != 0) {
    FUN_0065a620(puVar2);
  }
  return 0;
}

