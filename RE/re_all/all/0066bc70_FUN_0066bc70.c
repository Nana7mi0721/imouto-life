
int FUN_0066bc70(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  
  iVar1 = FUN_00669100(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0x74) = 0x8000;
    *(undefined4 *)(iVar1 + 0x2c0) = 0x2000;
    *(uint *)(iVar1 + 0x78) = *(uint *)(iVar1 + 0x78) | 0x300000;
    FUN_006685d0(iVar1,0,0);
  }
  return iVar1;
}

