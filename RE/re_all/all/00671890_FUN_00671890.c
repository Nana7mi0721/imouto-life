
void FUN_00671890(int param_1,undefined4 *param_2)

{
  byte bVar1;
  uint uVar2;
  undefined4 *puVar3;
  int local_10;
  uint local_c;
  char local_8;
  char local_7;
  char local_6;
  byte local_5;
  undefined3 uStack_4;
  
  if (param_1 != 0) {
    if ((*(int *)(param_1 + 0x118) == 0) && (*(char *)(param_1 + 0x155) == '\0')) {
      if ((*(uint *)(param_1 + 0x74) & 0x400) == 0) {
        FUN_00668620(param_1,s_png_write_info_was_never_called_b_00a0c904);
      }
      FUN_00679150(param_1);
    }
    if ((*(char *)(param_1 + 0x154) != '\0') && ((*(byte *)(param_1 + 0x7c) & 2) != 0)) {
      switch(*(undefined1 *)(param_1 + 0x155)) {
      case 0:
        if ((*(byte *)(param_1 + 0x118) & 7) != 0) {
          FUN_00679300(param_1);
          return;
        }
        break;
      case 1:
        if (((*(byte *)(param_1 + 0x118) & 7) != 0) || (*(uint *)(param_1 + 0x100) < 5)) {
          FUN_00679300(param_1);
          return;
        }
        break;
      case 2:
        if (((byte)*(undefined4 *)(param_1 + 0x118) & 7) != 4) {
          FUN_00679300(param_1);
          return;
        }
        break;
      case 3:
        if (((*(byte *)(param_1 + 0x118) & 3) != 0) || (*(uint *)(param_1 + 0x100) < 3)) {
          FUN_00679300(param_1);
          return;
        }
        break;
      case 4:
        if (((byte)*(undefined4 *)(param_1 + 0x118) & 3) != 2) {
          FUN_00679300(param_1);
          return;
        }
        break;
      case 5:
        if (((*(byte *)(param_1 + 0x118) & 1) != 0) || (*(uint *)(param_1 + 0x100) < 2)) {
          FUN_00679300(param_1);
          return;
        }
        break;
      case 6:
        if ((*(byte *)(param_1 + 0x118) & 1) == 0) {
          FUN_00679300(param_1);
          return;
        }
      }
    }
    local_7 = *(char *)(param_1 + 0x159);
    local_6 = *(char *)(param_1 + 0x15c);
    local_8 = *(char *)(param_1 + 0x157);
    bVar1 = local_7 * local_6;
    local_10 = *(int *)(param_1 + 0x10c);
    _local_5 = CONCAT31(uStack_4,bVar1);
    if (bVar1 < 8) {
      local_c = (uint)bVar1 * local_10 + 7 >> 3;
    }
    else {
      local_c = (uint)(bVar1 >> 3) * local_10;
    }
    puVar3 = (undefined4 *)(*(int *)(param_1 + 0x124) + 1);
    for (uVar2 = local_c >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
      *puVar3 = *param_2;
      param_2 = param_2 + 1;
      puVar3 = puVar3 + 1;
    }
    for (uVar2 = local_c & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
      *(undefined1 *)puVar3 = *(undefined1 *)param_2;
      param_2 = (undefined4 *)((int)param_2 + 1);
      puVar3 = (undefined4 *)((int)puVar3 + 1);
    }
    if ((((*(char *)(param_1 + 0x154) != '\0') && (*(byte *)(param_1 + 0x155) < 6)) &&
        ((*(byte *)(param_1 + 0x7c) & 2) != 0)) &&
       (FUN_00679450(&local_10,*(int *)(param_1 + 0x124) + 1,*(byte *)(param_1 + 0x155)),
       local_10 == 0)) {
      FUN_00679300(param_1);
      return;
    }
    if (*(int *)(param_1 + 0x7c) != 0) {
      FUN_0067a300(param_1,&local_10);
    }
    if ((local_5 != *(char *)(param_1 + 0x15a)) || (local_5 != *(char *)(param_1 + 0x15f))) {
      FUN_00668620(param_1,s_internal_write_transform_logic_e_00a0c8dc);
    }
    if (((*(byte *)(param_1 + 0x268) & 4) != 0) && (*(char *)(param_1 + 0x26c) == '@')) {
      FUN_00671b70(&local_10,*(int *)(param_1 + 0x124) + 1);
    }
    if ((local_8 == '\x03') && (-1 < *(int *)(param_1 + 0x14c))) {
      FUN_0066cfb0(param_1,&local_10);
    }
    FUN_006796c0(param_1,&local_10);
    if (*(code **)(param_1 + 0x1c8) != (code *)0x0) {
      (**(code **)(param_1 + 0x1c8))
                (param_1,*(undefined4 *)(param_1 + 0x118),*(undefined1 *)(param_1 + 0x155));
    }
  }
  return;
}

