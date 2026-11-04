
void FUN_006712d0(int param_1,int param_2,byte param_3)

{
  int iVar1;
  uint uVar2;
  
  if ((*(int *)(param_2 + 0xf0) != 0) &&
     (uVar2 = *(uint *)(param_2 + 0xec), uVar2 < uVar2 + *(int *)(param_2 + 0xf0) * 0x14)) {
    do {
      if ((((*(byte *)(uVar2 + 0x10) & param_3) != 0) &&
          (iVar1 = FUN_006696f0(param_1,uVar2), iVar1 != 1)) &&
         ((((*(byte *)(uVar2 + 3) & 0x20) != 0 || (iVar1 == 3)) ||
          ((iVar1 == 0 && (*(int *)(param_1 + 0x254) == 3)))))) {
        if (*(int *)(uVar2 + 0xc) == 0) {
          FUN_006687b0(param_1,s_Writing_zero_length_unknown_chun_00a0c844);
        }
        FUN_006773f0(param_1,uVar2,*(undefined4 *)(uVar2 + 8),*(undefined4 *)(uVar2 + 0xc));
      }
      uVar2 = uVar2 + 0x14;
    } while (uVar2 < (uint)(*(int *)(param_2 + 0xec) + *(int *)(param_2 + 0xf0) * 0x14));
  }
  return;
}

