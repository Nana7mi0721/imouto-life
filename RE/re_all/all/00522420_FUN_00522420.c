
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_00522420(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  undefined4 *puVar4;
  uint uVar5;
  int iVar6;
  int local_b8;
  int local_b4;
  int local_b0;
  int local_ac;
  int local_a8;
  int local_a4;
  int local_a0;
  int local_9c;
  int local_98;
  int local_94;
  undefined1 local_90 [16];
  undefined1 local_80 [16];
  undefined1 local_70 [16];
  undefined1 local_60 [16];
  undefined1 local_50 [16];
  undefined1 local_40 [16];
  undefined1 local_30 [16];
  undefined1 local_20 [16];
  undefined1 local_10 [16];
  
  if ((DAT_00a37e60 == 0) || (DAT_00a37e64 == 0)) {
    DAT_00a37e60 = 0x280;
    DAT_00a37e64 = 0x1e0;
    DAT_00a37e68 = 0x280;
    DAT_00a37e6c = 0x1e0;
    FUN_00584ed0(0x280,0x1e0);
  }
  uVar5 = -(uint)(DAT_00a37eec != 0) & _DAT_00a37ef0;
  if (DAT_00a37e70 == 0) {
    DAT_00a37e70 = 0x10;
    FUN_005811a0(0);
  }
  DAT_00a37e80 = DAT_00a37e7c;
  iVar3 = DAT_00a37ef8;
  do {
    while (DAT_00a37e80 == 0) {
      if (iVar3 == 0) {
        iVar1 = FUN_00567fe0();
        iVar3 = DAT_00a37ef8;
        if (-1 < iVar1) goto LAB_0052261e;
        DAT_00a37e80 = 2;
      }
      else {
LAB_0052261e:
        if ((DAT_00a37e60 <= *(int *)(uVar5 * 0x130 + 0x10 + iVar3)) &&
           (DAT_00a37e64 <= *(int *)(uVar5 * 0x130 + 0x14 + iVar3))) {
          iVar3 = iVar3 + uVar5 * 0x130;
          DAT_00a37e98 = *(undefined4 *)(iVar3 + 0x24);
          DAT_00a37e94 = *(undefined4 *)(iVar3 + 0x20);
          DAT_00a37e90 = *(undefined4 *)(iVar3 + 0x14);
          DAT_00a37e8c = *(undefined4 *)(iVar3 + 0x10);
          return 0;
        }
        DAT_00a37e80 = 2;
      }
    }
    if (DAT_00a37e80 != 1) {
      if (DAT_00a37e80 != 2) {
        return 0;
      }
      local_a0 = -1;
      local_b0 = -1;
      local_ac = -1;
      local_9c = 0;
      local_94 = 0;
      local_a4 = 0;
      local_98 = 0;
      local_a8 = 0;
      local_b4 = 0;
      if (iVar3 == 0) {
        iVar3 = FUN_00567fe0();
        if (-1 < iVar3) {
          iVar3 = DAT_00a37ef8;
          goto LAB_00522697;
        }
        local_b8 = -1;
      }
      else {
LAB_00522697:
        if (DAT_00a37ef4 < 1) {
          local_b8 = -1;
        }
        else {
          local_b8 = *(int *)(iVar3 + 0x128);
        }
      }
      iVar6 = 0;
      iVar3 = 0;
      iVar1 = 0;
      if (local_b8 < 1) goto LAB_0052277f;
      break;
    }
    if (iVar3 == 0) {
      iVar1 = FUN_00567fe0();
      iVar3 = DAT_00a37ef8;
      if (-1 < iVar1) goto LAB_005224d2;
      local_b8 = -1;
    }
    else {
LAB_005224d2:
      if (((int)uVar5 < 0) || (DAT_00a37ef4 <= (int)uVar5)) {
        local_b8 = -1;
      }
      else {
        local_b8 = *(int *)(uVar5 * 0x130 + 0x128 + iVar3);
      }
    }
    iVar1 = 0;
    local_a4 = -1;
    local_a0 = -1;
    local_a8 = -1;
    local_9c = -1;
    local_ac = -1;
    local_b0 = -1;
    if (0 < local_b8) {
      do {
        piVar2 = (int *)FUN_00516870(local_90,iVar1,uVar5);
        iVar3 = *piVar2 / DAT_00a37e60;
        if (*piVar2 % DAT_00a37e60 == 0) {
          if (piVar2[1] % DAT_00a37e64 == 0) {
            if (iVar3 == piVar2[1] / DAT_00a37e64) {
              if (local_a0 < 0) {
LAB_0052256e:
                local_a4 = iVar1;
                local_a0 = iVar3;
              }
              else if (iVar3 < local_a0) goto LAB_0052256e;
              if (DAT_00a37e70 == piVar2[2]) {
                if (local_9c < 0) {
LAB_0052258a:
                  local_a8 = iVar1;
                  local_9c = iVar3;
                }
                else if (iVar3 < local_9c) goto LAB_0052258a;
                if (DAT_00a37e74 != 0) {
                  if (DAT_00a37e74 != piVar2[3]) goto LAB_005225ba;
                }
                if (-1 < local_b0) {
                  if (local_b0 <= iVar3) goto LAB_005225ba;
                }
                local_b0 = iVar3;
                local_ac = iVar1;
                if (iVar3 == 1) break;
              }
            }
          }
        }
LAB_005225ba:
        iVar1 = iVar1 + 1;
      } while (iVar1 < local_b8);
      if (local_ac != -1) {
        puVar4 = (undefined4 *)FUN_00516870(local_50,local_ac,uVar5);
        if (local_b0 == 1) {
          DAT_00a37e8c = *puVar4;
          DAT_00a37e90 = puVar4[1];
          DAT_00a37e94 = puVar4[2];
          DAT_00a37e98 = puVar4[3];
          return 0;
        }
        DAT_00a37e98 = puVar4[3];
        DAT_00a37e94 = puVar4[2];
        DAT_00a37e90 = puVar4[1];
        DAT_00a37e8c = *puVar4;
        DAT_00a37e80 = 2;
        return 0;
      }
      if (local_a8 != -1) {
        puVar4 = (undefined4 *)FUN_00516870(local_30,local_a8,uVar5);
        DAT_00a37e80 = 2;
        DAT_00a37e8c = *puVar4;
        DAT_00a37e90 = puVar4[1];
        DAT_00a37e94 = puVar4[2];
        DAT_00a37e98 = puVar4[3];
        return 0;
      }
      if (local_a4 != -1) {
        puVar4 = (undefined4 *)FUN_00516870(local_10,local_a4,uVar5);
        DAT_00a37e80 = 2;
        DAT_00a37e8c = *puVar4;
        DAT_00a37e90 = puVar4[1];
        DAT_00a37e94 = puVar4[2];
        DAT_00a37e98 = puVar4[3];
        return 0;
      }
      iVar3 = DAT_00a37ef8;
    }
    DAT_00a37e80 = 0;
  } while( true );
LAB_005226c0:
  piVar2 = (int *)FUN_00516870(local_40,iVar6,uVar5);
  iVar3 = *piVar2;
  iVar1 = piVar2[1];
  if (DAT_00a37e70 == piVar2[2]) {
    if (DAT_00a37e74 != 0) {
      if (DAT_00a37e74 != piVar2[3]) goto LAB_00522718;
    }
    if (local_a0 != -1) {
      if (iVar1 * iVar3 <= local_94 * local_9c) goto LAB_00522718;
    }
    local_a0 = iVar6;
    local_9c = iVar3;
    local_94 = iVar1;
  }
LAB_00522718:
  if (local_b0 == -1) {
LAB_00522731:
    local_b0 = iVar6;
    local_a4 = iVar3;
    local_98 = iVar1;
  }
  else if (local_98 * local_a4 < iVar1 * iVar3) goto LAB_00522731;
  if (piVar2[2] == DAT_00a37e70) {
    if (local_ac != -1) {
      if (iVar1 * iVar3 <= local_b4 * local_a8) goto LAB_0052276a;
    }
    local_b4 = iVar1;
    local_ac = iVar6;
    local_a8 = iVar3;
  }
LAB_0052276a:
  iVar6 = iVar6 + 1;
  if (local_b8 <= iVar6) {
    iVar3 = local_94;
    iVar1 = local_b4;
LAB_0052277f:
    if (local_98 * local_a4 <= iVar1 * local_a8) {
      puVar4 = (undefined4 *)FUN_00516870(local_60,local_ac,uVar5);
      DAT_00a37e8c = *puVar4;
      DAT_00a37e90 = puVar4[1];
      DAT_00a37e94 = puVar4[2];
      DAT_00a37e98 = puVar4[3];
      return 0;
    }
    if (local_98 * local_a4 <= iVar3 * local_9c) {
      puVar4 = (undefined4 *)FUN_00516870(local_20,local_a0,uVar5);
      DAT_00a37e8c = *puVar4;
      DAT_00a37e90 = puVar4[1];
      DAT_00a37e94 = puVar4[2];
      DAT_00a37e98 = puVar4[3];
      return 0;
    }
    if (local_b0 < 1) {
      puVar4 = (undefined4 *)FUN_00516870(local_70,0,uVar5);
      DAT_00a37e8c = *puVar4;
      DAT_00a37e90 = puVar4[1];
      DAT_00a37e94 = puVar4[2];
      DAT_00a37e98 = puVar4[3];
      return 0;
    }
    puVar4 = (undefined4 *)FUN_00516870(local_80,local_b0,uVar5);
    DAT_00a37e8c = *puVar4;
    DAT_00a37e90 = puVar4[1];
    DAT_00a37e94 = puVar4[2];
    DAT_00a37e98 = puVar4[3];
    return 0;
  }
  goto LAB_005226c0;
}

