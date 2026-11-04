
undefined4
FUN_005d1730(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            )

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  undefined4 auStack_188 [32];
  undefined4 auStack_108 [32];
  undefined4 auStack_88 [33];
  
  if (DAT_00ee9b3c != (code *)0x0) {
    (*DAT_00ee9b3c)(DAT_00ee9b40);
  }
  if (DAT_00a4973c == 0) {
    FUN_00567600();
  }
  if (param_1 == 1) {
    FUN_005173e0(param_2,param_3);
    DAT_00a37e70 = param_4;
    DAT_00a37e74 = param_5;
  }
  else {
    FUN_0054f3a0();
    FUN_0054f350();
  }
  if (DAT_00a4973c == 0) {
    DAT_00a37e80 = DAT_00a37e7c;
    FUN_005d1690();
    FUN_005c0250();
    FUN_0057b250();
    if (param_1 == 0) {
      puVar2 = &DAT_00a38358;
      puVar3 = auStack_108;
      for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      puVar2 = &DAT_00a38420;
      puVar3 = auStack_188;
      for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
      puVar2 = &DAT_00a38718;
      puVar3 = auStack_88;
      for (iVar1 = 0x20; iVar1 != 0; iVar1 = iVar1 + -1) {
        *puVar3 = *puVar2;
        puVar2 = puVar2 + 1;
        puVar3 = puVar3 + 1;
      }
    }
    FUN_0052aa40(0,DAT_00a38120,DAT_00a38140,0);
    FUN_005d0880();
    FUN_00517640();
    FUN_00527130();
    if (DAT_00ee9b34 != (code *)0x0) {
      (*DAT_00ee9b34)(DAT_00ee9b38);
    }
    FUN_005cb6f0();
    FUN_00584d90(0);
    DAT_00a3d25c = 1;
    if (param_1 == 0) {
      FUN_005217e0(DAT_00a38184,DAT_00a38188,DAT_00a3818c,DAT_00a38190);
      FUN_00521bf0(&DAT_00a38290);
      FUN_00521cd0(auStack_108);
      FUN_00528b10(auStack_188);
      FUN_00521d40(auStack_88);
    }
    iVar1 = 1;
    if (1 < DAT_00a37da8) {
      do {
        FUN_0052aa40(iVar1,(&DAT_00a38120)[iVar1],(&DAT_00a38140)[iVar1],0);
        iVar1 = iVar1 + 1;
      } while (iVar1 < DAT_00a37da8);
    }
  }
  return 0;
}

