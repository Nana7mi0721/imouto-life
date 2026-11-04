
undefined4 FUN_0064e2e0(int param_1,uint param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_00653760(param_1,param_2,0);
  if ((iVar1 == 0) ||
     ((param_2 < 0x10000 &&
      ((*(uint *)(param_1 + 0x28 + (uint)(*(ushort *)(iVar1 + 0x18) >> 5) * 4) &
       1 << ((byte)*(ushort *)(iVar1 + 0x18) & 0x1f)) == 0)))) {
    return 0;
  }
  uVar2 = (**(code **)(param_1 + 0x2a0))(param_1,param_2,param_3);
  return uVar2;
}

