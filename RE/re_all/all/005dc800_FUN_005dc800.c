
undefined4 FUN_005dc800(int param_1)

{
  int iVar1;
  int unaff_ESI;
  undefined4 uStack_6c;
  undefined4 *puStack_68;
  undefined4 *puStack_64;
  undefined4 uStack_60;
  undefined4 local_54 [3];
  int iStack_48;
  int iStack_44;
  undefined4 uStack_38;
  int iStack_34;
  
  if (*(int *)(param_1 + 0x6a) != *(int *)(param_1 + 0x460)) {
    if (*(int *)(param_1 + 0x460) < *(int *)(param_1 + 0x6a)) {
      puStack_64 = *(undefined4 **)(param_1 + 0x52);
      uStack_60 = 0;
      puStack_68 = (undefined4 *)0x5dc82b;
      (*DAT_00f3a118)();
      puStack_68 = (undefined4 *)0x4;
      uStack_6c = 0;
      (*DAT_00f3a110)(param_1 + 0x52,0,*(undefined4 *)(param_1 + 0x4a),param_1 + 0x38,0,0);
      *(undefined4 *)(param_1 + 0x6a) = 0;
      *(undefined4 *)(param_1 + 0x66) = 0;
    }
    if (*(int *)(param_1 + 0x6a) < *(int *)(param_1 + 0x460) + -0x2800) {
      uStack_60 = 0x54;
      puStack_68 = local_54;
      puStack_64 = (undefined4 *)0x0;
      uStack_6c = 0x5dc874;
      FUN_0056d380();
      iStack_48 = *(int *)(param_1 + 0x56) + *(int *)(param_1 + 0x66);
      iVar1 = *(int *)(param_1 + 0x5a) - *(int *)(param_1 + 0x66);
      local_54[0] = 0x54;
      iStack_44 = 0x800;
      if (iVar1 < 0x801) {
        iStack_44 = iVar1;
      }
      uStack_38 = *(undefined4 *)(param_1 + 0x6e);
      iStack_34 = *(int *)(param_1 + 0x450);
      if (*(int *)(param_1 + 0x460) < iStack_34 + *(int *)(param_1 + 0x6a)) {
        iStack_34 = *(int *)(param_1 + 0x460) - *(int *)(param_1 + 0x6a);
      }
      puStack_68 = *(undefined4 **)(param_1 + 0x52);
      uStack_60 = 0;
      puStack_64 = local_54;
      uStack_6c = 0x5dc8da;
      iVar1 = (*DAT_00f3a120)();
      if (iVar1 != 0) {
        return 0xffffffff;
      }
      uStack_6c = 4;
      (*DAT_00f3a124)(*(undefined4 *)(param_1 + 0x52),&uStack_60);
      *(int *)(param_1 + 0x6a) = *(int *)(param_1 + 0x6a) + iStack_48;
      *(int *)(param_1 + 0x66) = *(int *)(param_1 + 0x66) + unaff_ESI;
      (*DAT_00f3a128)(*(undefined4 *)(param_1 + 0x52),&uStack_6c,0);
    }
  }
  if (*(int *)(param_1 + 0x5e) != *(int *)(param_1 + 0x5a)) {
    uStack_60 = 0x54;
    puStack_68 = local_54;
    puStack_64 = (undefined4 *)0x0;
    uStack_6c = 0x5dc92c;
    FUN_0056d380();
    iStack_48 = *(int *)(param_1 + 0x56) + *(int *)(param_1 + 0x5e);
    iVar1 = *(int *)(param_1 + 0x5a) - *(int *)(param_1 + 0x5e);
    local_54[0] = 0x54;
    iStack_44 = 0x800;
    if (iVar1 < 0x801) {
      iStack_44 = iVar1;
    }
    uStack_38 = *(undefined4 *)(param_1 + 0x44c);
    iStack_34 = *(undefined4 *)(param_1 + 0x450);
    uStack_60 = 0;
    puStack_64 = local_54;
    puStack_68 = *(undefined4 **)(param_1 + 0x4e);
    uStack_6c = 0x5dc980;
    iVar1 = (*DAT_00f3a120)();
    if (iVar1 == 0) {
      uStack_6c = 4;
      (*DAT_00f3a124)(*(undefined4 *)(param_1 + 0x4e),&uStack_60);
      iVar1 = iStack_48;
      *(int *)(param_1 + 0x454) = iStack_48;
      *(int *)(param_1 + 0x5e) = *(int *)(param_1 + 0x5e) + unaff_ESI;
      (*DAT_00f3a128)(*(undefined4 *)(param_1 + 0x4e),&uStack_6c,0);
      if (iVar1 != 0) {
        return 0;
      }
      *(undefined4 *)(param_1 + 0x454) = 0;
      *(undefined4 *)(param_1 + 0x5e) = *(undefined4 *)(param_1 + 0x5a);
    }
  }
  return 0xffffffff;
}

