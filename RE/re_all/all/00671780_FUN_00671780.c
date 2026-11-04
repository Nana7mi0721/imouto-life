
int FUN_00671780(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  
  iVar1 = FUN_00669100(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
  if (iVar1 != 0) {
    *(undefined4 *)(iVar1 + 0xc4) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0xd8) = 0xffffffff;
    *(undefined4 *)(iVar1 + 0xc0) = 0x2000;
    *(undefined4 *)(iVar1 + 0xd4) = 1;
    *(undefined4 *)(iVar1 + 0xd0) = 8;
    *(undefined4 *)(iVar1 + 0xcc) = 0xf;
    *(undefined4 *)(iVar1 + 200) = 8;
    *(undefined4 *)(iVar1 + 0xe8) = 0;
    *(undefined4 *)(iVar1 + 0xe4) = 8;
    *(undefined4 *)(iVar1 + 0xe0) = 0xf;
    *(undefined4 *)(iVar1 + 0xdc) = 8;
    *(uint *)(iVar1 + 0x78) = *(uint *)(iVar1 + 0x78) | 0x200000;
    FUN_00671110(iVar1,0,0,0);
  }
  return iVar1;
}

