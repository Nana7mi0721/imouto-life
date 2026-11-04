
undefined4 FUN_0065e6b0(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  
  if ((0 < *(int *)(param_1 + 0x260)) && (uVar1 = *(uint *)(param_1 + 0xc), (uVar1 & 0x100000) != 0)
     ) {
    if (((uVar1 & *(ushort *)(param_1 + 0x5e)) == 0) && ((uVar1 & 0x100) == 0)) {
      FUN_0065a770(*(undefined4 *)(param_1 + 0x24c),*(int *)(param_1 + 0x260));
    }
    if ((*(uint *)(param_1 + 0xc) & 0x400) == 0) {
      uVar2 = *(undefined4 *)(param_1 + 0x1c4);
    }
    else {
      uVar2 = *(undefined4 *)(param_1 + 0x1ec);
    }
    iVar3 = FUN_0065e450(param_1,uVar2,*(undefined4 *)(param_1 + 0x24c),
                         *(undefined4 *)(param_1 + 0x260));
    if (iVar3 == 0) {
      return 0;
    }
    *(undefined4 *)(param_1 + 0x260) = 0;
    *(undefined4 *)(param_1 + 0x25c) = *(undefined4 *)(param_1 + 0x24c);
  }
  return 1;
}

