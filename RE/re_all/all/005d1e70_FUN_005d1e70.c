
undefined4 FUN_005d1e70(uint param_1)

{
  undefined4 *puVar1;
  int iVar2;
  
  iVar2 = param_1;
  puVar1 = (undefined4 *)(param_1 + 0x14);
  param_1 = *(uint *)(param_1 + 0x18) & 0xff;
  (**(code **)(*DAT_00f3a074 + 0xd4))
            (DAT_00f3a074,*(undefined4 *)(iVar2 + 0xc),*(undefined4 *)(iVar2 + 0x10),
             *(undefined4 *)*puVar1,param_1);
  return 0;
}

