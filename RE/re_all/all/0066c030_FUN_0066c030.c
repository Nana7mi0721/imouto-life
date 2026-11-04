
void FUN_0066c030(int param_1,uint param_2,uint param_3)

{
  byte bVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  bool bVar5;
  char *pcVar6;
  undefined4 uVar7;
  int local_10;
  uint local_c;
  undefined1 local_8;
  undefined1 local_7;
  undefined1 local_6;
  byte local_5;
  undefined3 uStack_4;
  
  if (param_1 == 0) {
    return;
  }
  if ((*(byte *)(param_1 + 0x78) & 0x40) == 0) {
    FUN_00676ef0(param_1);
  }
  local_8 = *(undefined1 *)(param_1 + 0x157);
  local_7 = *(undefined1 *)(param_1 + 0x158);
  local_10 = *(int *)(param_1 + 0x114);
  local_6 = *(undefined1 *)(param_1 + 0x15b);
  bVar1 = *(byte *)(param_1 + 0x15a);
  _local_5 = CONCAT31(uStack_4,bVar1);
  if (bVar1 < 8) {
    local_c = (uint)bVar1 * local_10 + 7 >> 3;
  }
  else {
    local_c = (uint)(bVar1 >> 3) * local_10;
  }
  if ((*(char *)(param_1 + 0x154) == '\0') || ((*(byte *)(param_1 + 0x7c) & 2) == 0))
  goto LAB_0066c19c;
  switch(*(undefined1 *)(param_1 + 0x155)) {
  case 0:
    uVar2 = param_3;
    if ((*(byte *)(param_1 + 0x118) & 7) == 0) goto LAB_0066c19c;
joined_r0x0066c168:
    if (uVar2 == 0) goto LAB_0066c102;
    goto LAB_0066c0f6;
  case 1:
    if ((*(byte *)(param_1 + 0x118) & 7) == 0) {
      bVar5 = *(uint *)(param_1 + 0x100) < 5;
LAB_0066c17c:
      if (!bVar5) goto LAB_0066c19c;
    }
    break;
  case 2:
    if (((byte)*(uint *)(param_1 + 0x118) & 7) == 4) goto LAB_0066c19c;
    if (param_3 == 0) goto LAB_0066c102;
    uVar2 = *(uint *)(param_1 + 0x118) & 4;
    goto LAB_0066c184;
  case 3:
    if ((*(byte *)(param_1 + 0x118) & 3) == 0) {
      bVar5 = *(uint *)(param_1 + 0x100) < 3;
      goto LAB_0066c17c;
    }
    break;
  case 4:
    if (((byte)*(uint *)(param_1 + 0x118) & 3) != 2) {
      if (param_3 == 0) goto LAB_0066c102;
      uVar2 = *(uint *)(param_1 + 0x118) & 2;
      goto joined_r0x0066c168;
    }
    goto LAB_0066c19c;
  case 5:
    if ((*(byte *)(param_1 + 0x118) & 1) == 0) {
      bVar5 = *(uint *)(param_1 + 0x100) < 2;
      goto LAB_0066c17c;
    }
    break;
  default:
    if ((*(byte *)(param_1 + 0x118) & 1) == 0) goto LAB_0066c102;
LAB_0066c19c:
    if ((*(byte *)(param_1 + 0x74) & 4) == 0) {
      FUN_00668620(param_1,s_Invalid_attempt_to_read_row_data_00a0c5a0);
    }
    FUN_00676b80(param_1,*(undefined4 *)(param_1 + 0x124),local_c + 1);
    bVar1 = **(byte **)(param_1 + 0x124);
    if (bVar1 != 0) {
      if (bVar1 < 5) {
        FUN_006768a0(param_1,&local_10,*(byte **)(param_1 + 0x124) + 1,*(int *)(param_1 + 0x120) + 1
                     ,bVar1);
      }
      else {
        FUN_00668620(param_1,s_bad_adaptive_filter_value_00a0c584);
      }
    }
    puVar3 = *(undefined4 **)(param_1 + 0x124);
    puVar4 = *(undefined4 **)(param_1 + 0x120);
    for (uVar2 = local_c + 1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar4 = *puVar3;
      puVar3 = puVar3 + 1;
      puVar4 = puVar4 + 1;
    }
    for (uVar2 = local_c + 1 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar4 = *(undefined1 *)puVar3;
      puVar3 = (undefined4 *)((int)puVar3 + 1);
      puVar4 = (undefined4 *)((int)puVar4 + 1);
    }
    if (((*(byte *)(param_1 + 0x268) & 4) != 0) && (*(char *)(param_1 + 0x26c) == '@')) {
      FUN_0066c370(&local_10,*(int *)(param_1 + 0x124) + 1);
    }
    if (*(int *)(param_1 + 0x7c) != 0) {
      FUN_0066e120(param_1,&local_10);
    }
    if (*(byte *)(param_1 + 0x15f) == 0) {
      *(byte *)(param_1 + 0x15f) = local_5;
      if (*(byte *)(param_1 + 0x15e) < local_5) {
        pcVar6 = s_sequential_row_overflow_00a0c56c;
LAB_0066c294:
        FUN_00668620(param_1,pcVar6);
      }
    }
    else if (*(byte *)(param_1 + 0x15f) != local_5) {
      pcVar6 = s_internal_sequential_row_size_cal_00a0c53c;
      goto LAB_0066c294;
    }
    if ((*(char *)(param_1 + 0x154) == '\0') || ((*(uint *)(param_1 + 0x7c) & 2) == 0)) {
      if (param_2 != 0) {
        FUN_00675f00(param_1,param_2,0xffffffff);
      }
      if (param_3 == 0) goto LAB_0066c31d;
      uVar7 = 0xffffffff;
      param_2 = param_3;
    }
    else {
      if (*(byte *)(param_1 + 0x155) < 6) {
        FUN_00676440(&local_10,*(int *)(param_1 + 0x124) + 1,*(byte *)(param_1 + 0x155),
                     *(uint *)(param_1 + 0x7c));
      }
      if (param_3 != 0) {
        FUN_00675f00(param_1,param_3,1);
      }
      if (param_2 == 0) goto LAB_0066c31d;
      uVar7 = 0;
    }
    FUN_00675f00(param_1,param_2,uVar7);
LAB_0066c31d:
    FUN_00676de0(param_1);
    if (*(code **)(param_1 + 0x1c4) != (code *)0x0) {
      (**(code **)(param_1 + 0x1c4))
                (param_1,*(undefined4 *)(param_1 + 0x118),*(undefined1 *)(param_1 + 0x155));
    }
    return;
  }
  uVar2 = param_3;
LAB_0066c184:
  if (uVar2 != 0) {
LAB_0066c0f6:
    FUN_00675f00(param_1,param_3,1);
  }
LAB_0066c102:
  FUN_00676de0(param_1);
  return;
}

