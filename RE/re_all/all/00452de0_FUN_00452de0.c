
undefined4 __fastcall FUN_00452de0(int param_1)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined4 *puVar4;
  uint *puVar5;
  uint uVar6;
  int local_1c;
  int local_18;
  int local_14;
  uint local_10;
  
  iVar2 = FUN_004ce080();
  if (iVar2 < 1) {
    local_14 = 0;
    puVar5 = (uint *)FUN_004ce990(1);
    uVar1 = *puVar5;
    for (local_1c = 0; local_1c < (int)(uVar1 & 0xf); local_1c = local_1c + 1) {
      puVar4 = (undefined4 *)FUN_004ce990(local_1c * 3 + 2);
      uVar6 = FUN_00487080(*puVar4);
      puVar5 = (uint *)FUN_004ce990(local_1c * 3 + 4);
      if ((*puVar5 & 0x10) == 0) {
        puVar4 = (undefined4 *)FUN_004ce990(local_1c * 3 + 3);
        local_10 = FUN_00487080(*puVar4);
      }
      else {
        puVar5 = (uint *)FUN_004ce990(local_1c * 3 + 3);
        local_10 = *puVar5;
      }
      puVar5 = (uint *)FUN_004ce990(local_1c * 3 + 4);
      switch(*puVar5 & 0xf) {
      case 0:
        if ((int)local_10 < (int)uVar6) {
          local_14 = local_1c + 1;
        }
        break;
      case 1:
        if ((int)local_10 <= (int)uVar6) {
          local_14 = local_1c + 1;
        }
        break;
      case 2:
        if (uVar6 == local_10) {
          local_14 = local_1c + 1;
        }
        break;
      case 3:
        if ((int)uVar6 <= (int)local_10) {
          local_14 = local_1c + 1;
        }
        break;
      case 4:
        if ((int)uVar6 < (int)local_10) {
          local_14 = local_1c + 1;
        }
        break;
      case 5:
        if (uVar6 != local_10) {
          local_14 = local_1c + 1;
        }
        break;
      case 6:
        if ((uVar6 & local_10) == local_10) {
          local_14 = local_1c + 1;
        }
      }
      if (local_14 != 0) break;
    }
    *(int *)(param_1 + 0x38 + *(char *)(*(int *)(param_1 + 0x898) + 0x10) * 4) = local_14;
  }
  else {
    *(undefined4 *)(param_1 + 0x38 + *(char *)(*(int *)(param_1 + 0x898) + 0x10) * 4) = 0xffffff9c;
    for (local_18 = 0; piVar3 = (int *)FUN_004ce990(1), local_18 < *piVar3; local_18 = local_18 + 1)
    {
      puVar4 = (undefined4 *)FUN_004ce990(local_18 + 2);
      switch(*puVar4) {
      case 0:
        puVar4 = (undefined4 *)FUN_004ce990(local_18 << 1);
        piVar3 = (int *)*puVar4;
        puVar4 = (undefined4 *)FUN_004ce990(local_18 * 2 + 1);
        if (*(int *)*puVar4 < *piVar3) {
          puVar4 = (undefined4 *)FUN_004ce990(local_18 + 5);
          *(undefined4 *)(param_1 + 8) = *puVar4;
          return 1;
        }
        break;
      case 1:
        puVar4 = (undefined4 *)FUN_004ce990(local_18 << 1);
        piVar3 = (int *)*puVar4;
        puVar4 = (undefined4 *)FUN_004ce990(local_18 * 2 + 1);
        if (*(int *)*puVar4 <= *piVar3) {
          puVar4 = (undefined4 *)FUN_004ce990(local_18 + 5);
          *(undefined4 *)(param_1 + 8) = *puVar4;
          return 1;
        }
        break;
      case 2:
        puVar4 = (undefined4 *)FUN_004ce990(local_18 << 1);
        piVar3 = (int *)*puVar4;
        puVar4 = (undefined4 *)FUN_004ce990(local_18 * 2 + 1);
        if (*piVar3 == *(int *)*puVar4) {
          puVar4 = (undefined4 *)FUN_004ce990(local_18 + 5);
          *(undefined4 *)(param_1 + 8) = *puVar4;
          return 1;
        }
        break;
      case 3:
        puVar4 = (undefined4 *)FUN_004ce990(local_18 << 1);
        piVar3 = (int *)*puVar4;
        puVar4 = (undefined4 *)FUN_004ce990(local_18 * 2 + 1);
        if (*piVar3 <= *(int *)*puVar4) {
          puVar4 = (undefined4 *)FUN_004ce990(local_18 + 5);
          *(undefined4 *)(param_1 + 8) = *puVar4;
          return 1;
        }
        break;
      case 4:
        puVar4 = (undefined4 *)FUN_004ce990(local_18 << 1);
        piVar3 = (int *)*puVar4;
        puVar4 = (undefined4 *)FUN_004ce990(local_18 * 2 + 1);
        if (*piVar3 < *(int *)*puVar4) {
          puVar4 = (undefined4 *)FUN_004ce990(local_18 + 5);
          *(undefined4 *)(param_1 + 8) = *puVar4;
          return 1;
        }
        break;
      case 5:
        puVar4 = (undefined4 *)FUN_004ce990(local_18 << 1);
        piVar3 = (int *)*puVar4;
        puVar4 = (undefined4 *)FUN_004ce990(local_18 * 2 + 1);
        if (*piVar3 != *(int *)*puVar4) {
          puVar4 = (undefined4 *)FUN_004ce990(local_18 + 5);
          *(undefined4 *)(param_1 + 8) = *puVar4;
          return 1;
        }
        break;
      case 6:
        puVar4 = (undefined4 *)FUN_004ce990(local_18 << 1);
        puVar5 = (uint *)*puVar4;
        puVar4 = (undefined4 *)FUN_004ce990(local_18 * 2 + 1);
        uVar1 = *puVar5;
        uVar6 = *(uint *)*puVar4;
        puVar4 = (undefined4 *)FUN_004ce990(local_18 * 2 + 1);
        if ((uVar1 & uVar6) == *(uint *)*puVar4) {
          puVar4 = (undefined4 *)FUN_004ce990(local_18 + 5);
          *(undefined4 *)(param_1 + 8) = *puVar4;
          return 1;
        }
      }
    }
    puVar4 = (undefined4 *)FUN_004ce990(8);
    *(undefined4 *)(param_1 + 8) = *puVar4;
  }
  return 1;
}

