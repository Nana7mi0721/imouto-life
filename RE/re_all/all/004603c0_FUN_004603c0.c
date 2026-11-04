
undefined4 FUN_004603c0(void)

{
  undefined4 *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  undefined4 extraout_var;
  int local_c;
  
  puVar1 = (undefined4 *)FUN_004ce990(1);
  uVar4 = extraout_var;
  iVar2 = FUN_00487080(*puVar1);
  if (-1 < iVar2) {
    iVar3 = FUN_004b5c30(uVar4);
    if (iVar2 < iVar3) {
      uVar4 = FUN_004d0b90(iVar2);
      FUN_004743a0(uVar4);
      FUN_004cb840(&DAT_00a1687c);
      for (local_c = 0; local_c < 0xf; local_c = local_c + 1) {
        FUN_004cb840(&DAT_00a1687c + (local_c + 1) * 0x1c);
      }
      FUN_004f09c0(&DAT_00a16a4c);
      FUN_004f09c0(&DAT_00a180b0);
      FUN_004cd5b0(&DAT_00a16a3c);
      DAT_00a141f8 = 1;
      DAT_00a140cc = 1;
    }
  }
  return 1;
}

