
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0057f560(int param_1,uint param_2,uint *param_3,int param_4,int param_5)

{
  int *piVar1;
  int *piVar2;
  int *piVar3;
  int iVar4;
  undefined4 *puVar5;
  code *pcVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 local_54;
  undefined4 uStack_50;
  undefined4 *puStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  uint uStack_40;
  int iStack_3c;
  undefined4 local_38;
  uint local_34;
  uint local_30;
  undefined4 local_2c;
  undefined2 local_28;
  undefined4 *local_24;
  uint local_20;
  uint local_1c;
  undefined4 *local_14;
  
  piVar1 = (int *)(param_1 + 200);
  piVar2 = (int *)(param_1 + 0xcc);
  local_54 = 0;
  *piVar1 = 0;
  *piVar2 = 0;
  *(undefined4 *)(param_1 + 0xd0) = 0;
  *(undefined4 *)(param_1 + 0xd4) = 0;
  if (param_4 == 0) {
    local_38 = *param_3;
    local_34 = param_3[1];
    local_30 = param_3[2];
    local_2c = param_3[3];
    local_28 = (undefined2)param_3[4];
  }
  else {
    local_38 = *(uint *)(param_4 + 0x30);
    param_2 = (uint)*(ushort *)(param_4 + 0x3c) * *(int *)(param_4 + 0x2c);
    local_34 = *(uint *)(param_4 + 0x34);
    local_30 = *(uint *)(param_4 + 0x38);
    local_2c = *(uint *)(param_4 + 0x3c);
    local_28 = *(undefined2 *)(param_4 + 0x40);
  }
  if (DAT_00aa4fa0 == 0) {
    FUN_0056d380(&local_24,0,0x24);
    local_20 = (-(uint)(DAT_00aa4fa4 != 0) & 6) + 2 | 0x180e0;
    local_14 = &local_38;
    local_24 = (undefined4 *)0x24;
    local_1c = param_2;
    iVar4 = (**(code **)(*DAT_00aa4270 + 0xc))(DAT_00aa4270,&local_24,piVar1,0);
    if (iVar4 == 0) {
      return 0;
    }
    FUN_0056d380(&local_34,0,0x24);
    local_30 = (-(uint)(DAT_00aa4fa4 != 0) & 6) + 2 | 0xc0;
    local_24 = &uStack_48;
    local_34 = 0x24;
    local_2c = param_2;
    iVar4 = (**(code **)(*DAT_00aa4270 + 0xc))(DAT_00aa4270,&local_34,piVar1,0);
    if (iVar4 == 0) {
      return 0;
    }
    goto LAB_0057f97e;
  }
  if (param_5 == 0) {
    if (local_38._2_2_ == 1) {
      iVar4 = (int)((uint)local_2c._2_2_ * 2) >> 3;
      local_2c = CONCAT22(local_2c._2_2_,(short)iVar4);
      local_30 = iVar4 * local_34;
      local_38 = CONCAT22(2,(undefined2)local_38);
      local_54 = 1;
    }
  }
  else {
    if (DAT_00aa4254 == 0) {
      iVar4 = (*DAT_00aba190)(&DAT_0085f2f4,0,1,&DAT_0085e5a4,(undefined4 *)(param_1 + 0xd0));
    }
    else {
      iVar4 = (*DAT_00aa4260)();
    }
    if (iVar4 < 0) goto LAB_0057f97e;
    uStack_48 = *(undefined4 *)(param_1 + 0xd0);
    uStack_40 = local_38 >> 0x10;
    uStack_44 = 1;
    uStack_50 = 1;
    puStack_4c = &uStack_48;
    if (DAT_00aa4254 == 0) {
      iVar4 = (**(code **)(*DAT_00aa4270 + 0x24))
                        (DAT_00aa4270,piVar2,uStack_40,DAT_00a834f8,0,0,0,&uStack_50);
      if (iVar4 < 0) goto LAB_0057f97e;
      FUN_0056d420(param_1 + 0xd8,&DAT_00aa4274,0x34);
      uVar8 = 0x34;
    }
    else {
      iVar4 = (**(code **)(*DAT_00aa4270 + 0x18))();
      if (iVar4 < 0) goto LAB_0057f97e;
      FUN_0056d420(param_1 + 0xd8,&DAT_00aa488c,0x38);
      uVar8 = 0x38;
    }
    (**(code **)(*(int *)*piVar2 + 0x18))((int *)*piVar2,0,param_1 + 0xd8,uVar8,0);
    (**(code **)(*(int *)*piVar2 + 0x10))((int *)*piVar2,0,0);
  }
  *(uint *)(param_1 + 0x110) = local_38 >> 0x10;
  if (param_4 == 0) {
    iVar4 = FUN_00551420(param_2,local_54);
  }
  else {
    iVar4 = FUN_00551490(*(undefined4 *)(param_4 + 0x4c));
  }
  *(int *)(param_1 + 0x4c) = iVar4;
  if (iVar4 == 0) goto LAB_0057f97e;
  puVar5 = operator_new(8);
  if (puVar5 == (undefined4 *)0x0) {
    puVar5 = (undefined4 *)0x0;
  }
  else {
    *puVar5 = DxLib::SOUNDBUFFER_CALLBACK::vftable;
  }
  *(undefined4 **)(param_1 + 0xd4) = puVar5;
  uVar8 = _DAT_007d103c;
  if (puVar5 == (undefined4 *)0x0) goto LAB_0057f97e;
  puVar5[1] = param_1;
  if (DAT_00aa4254 == 0) {
    if (param_5 == 0) {
      puVar5 = (undefined4 *)0x0;
    }
    else {
      iStack_3c = *piVar2;
      uStack_48 = 0x80;
      uStack_40 = 0x80;
      puStack_4c = &uStack_48;
      puVar5 = &uStack_50;
      uStack_44 = DAT_00aa4f1c;
      uStack_50 = 2;
    }
    uVar7 = *(undefined4 *)(param_1 + 0xd4);
    pcVar6 = *(code **)(*DAT_00aa4270 + 0x20);
LAB_0057f87a:
    iVar4 = (*pcVar6)(DAT_00aa4270,piVar1,&local_38,0,uVar8,uVar7,puVar5,0);
  }
  else {
    if (param_5 == 0) {
      uVar7 = *(undefined4 *)(param_1 + 0xd4);
      puVar5 = (undefined4 *)0x0;
      pcVar6 = *(code **)(*DAT_00aa4270 + 0x14);
      goto LAB_0057f87a;
    }
    puStack_4c = &uStack_48;
    uStack_48 = 0x80;
    uStack_40 = 0x80;
    iStack_3c = *piVar2;
    uStack_44 = DAT_00aa4f20;
    uStack_50 = 2;
    iVar4 = (**(code **)(*DAT_00aa4270 + 0x14))
                      (DAT_00aa4270,piVar1,&local_38,0,uVar8,*(undefined4 *)(param_1 + 0xd4),
                       &uStack_50);
  }
  if (-1 < iVar4) {
    if (param_4 != 0) {
      iVar4 = 0;
      puVar5 = (undefined4 *)(param_4 + 8);
      do {
        FUN_00551c40(param_1,iVar4,*puVar5);
        iVar4 = iVar4 + 1;
        puVar5 = puVar5 + 1;
      } while (iVar4 < 8);
      FUN_005519c0(param_1,*(undefined4 *)(param_4 + 0x28));
      FUN_0055d3e0(param_1,*(undefined4 *)(param_4 + 4));
    }
    return 0;
  }
LAB_0057f97e:
  piVar3 = (int *)*piVar1;
  if (DAT_00aa4fa0 == 0) {
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 8))(piVar3);
      *piVar1 = 0;
    }
  }
  else {
    if (piVar3 != (int *)0x0) {
      (**(code **)(*piVar3 + 0x48))(piVar3);
      *piVar1 = 0;
    }
    piVar1 = (int *)*piVar2;
    if (piVar1 != (int *)0x0) {
      (**(code **)(*piVar1 + 0x48))(piVar1);
      *piVar2 = 0;
    }
    if (*(void **)(param_1 + 0xd4) != (void *)0x0) {
      _free(*(void **)(param_1 + 0xd4));
      *(undefined4 *)(param_1 + 0xd4) = 0;
      return 0xffffffff;
    }
  }
  return 0xffffffff;
}

