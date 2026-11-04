
uint FUN_004fad50(int param_1,int param_2,uint param_3)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint local_20;
  uint local_1c;
  uint local_18;
  uint local_14;
  uint local_10;
  
  local_14 = 0;
  local_10 = 0;
  if (param_1 == 0) {
    local_10 = 0xffffff9a;
  }
  else {
    piVar1 = *(int **)(param_1 + 0xe0);
    if (piVar1 == (int *)0x0) {
      local_10 = 0xffffff9a;
    }
    else if (*piVar1 == 0) {
      local_10 = 0xffffff9c;
    }
    else if (param_3 == 0) {
      local_10 = 0;
    }
    else {
      piVar1[4] = param_2;
      piVar1[5] = param_3;
      if (((piVar1[0x21] == 0) && ((uint)piVar1[0x20] < param_3)) && (piVar1[0x32] == 0)) {
        piVar1[5] = piVar1[0x20];
      }
      if (((piVar1[0x1f] + (uint)CARRY4(piVar1[2],piVar1[0x1e]) == 0) &&
          ((uint)(piVar1[2] + piVar1[0x1e]) < param_3)) && (piVar1[0x32] != 0)) {
        piVar1[5] = piVar1[0x1e] + piVar1[2];
      }
      do {
        do {
          while( true ) {
            if (piVar1[5] == 0) goto LAB_004fb202;
            if ((piVar1[2] == 0) && ((piVar1[0x1f] != 0 || (piVar1[0x1e] != 0)))) {
              local_18 = 0x4000;
              if ((piVar1[0x1f] == 0) && ((uint)piVar1[0x1e] < 0x4000)) {
                local_18 = piVar1[0x1e];
              }
              if (local_18 == 0) {
                return 0;
              }
              iVar4 = FUN_00401750(piVar1 + 0x22,piVar1[0x2d],piVar1[0x10] + piVar1[0x30],
                                   piVar1[0x11] + piVar1[0x31] +
                                   (uint)CARRY4(piVar1[0x10],piVar1[0x30]),0);
              if (iVar4 != 0) {
                return 0xffffffff;
              }
              uVar5 = (*(code *)piVar1[0x23])(piVar1[0x29],piVar1[0x2d],*piVar1,local_18);
              if (uVar5 != local_18) {
                return 0xffffffff;
              }
              uVar5 = piVar1[0x10];
              piVar1[0x10] = local_18 + piVar1[0x10];
              piVar1[0x11] = piVar1[0x11] + (uint)CARRY4(local_18,uVar5);
              uVar5 = piVar1[0x1e];
              piVar1[0x1e] = uVar5 - local_18;
              piVar1[0x1f] = piVar1[0x1f] - (uint)(uVar5 < local_18);
              piVar1[1] = *piVar1;
              piVar1[2] = local_18;
            }
            if ((piVar1[0x2e] != 0) && (piVar1[0x32] == 0)) break;
            if ((piVar1[2] == 0) && (piVar1[0x1e] == 0 && piVar1[0x1f] == 0)) {
              return -(uint)(local_10 != 0) & local_10;
            }
            if ((uint)piVar1[5] < (uint)piVar1[2]) {
              local_20 = piVar1[5];
            }
            else {
              local_20 = piVar1[2];
            }
            for (local_1c = 0; local_1c < local_20; local_1c = local_1c + 1) {
              *(undefined1 *)(piVar1[4] + local_1c) = *(undefined1 *)(piVar1[1] + local_1c);
            }
            uVar5 = piVar1[0x1a];
            piVar1[0x1a] = local_20 + piVar1[0x1a];
            piVar1[0x1b] = piVar1[0x1b] + (uint)CARRY4(local_20,uVar5);
            iVar4 = FUN_0067c560(piVar1[0x1c],piVar1[4],local_20);
            piVar1[0x1c] = iVar4;
            uVar5 = piVar1[0x20];
            piVar1[0x20] = uVar5 - local_20;
            piVar1[0x21] = piVar1[0x21] - (uint)(uVar5 < local_20);
            piVar1[2] = piVar1[2] - local_20;
            piVar1[5] = piVar1[5] - local_20;
            piVar1[4] = piVar1[4] + local_20;
            piVar1[1] = piVar1[1] + local_20;
            piVar1[6] = piVar1[6] + local_20;
            local_10 = local_10 + local_20;
          }
        } while (piVar1[0x2e] == 0xc);
        uVar5 = piVar1[6];
        iVar4 = piVar1[4];
        local_14 = FUN_0067abc0(piVar1 + 1,2);
        if ((-1 < (int)local_14) && (piVar1[7] != 0)) {
          local_14 = 0xfffffffd;
        }
        uVar2 = piVar1[6];
        uVar6 = uVar2 - uVar5;
        uVar3 = piVar1[0x1a];
        piVar1[0x1a] = uVar3 + uVar6;
        piVar1[0x1b] = (piVar1[0x1b] - (uint)(uVar2 < uVar5)) + (uint)CARRY4(uVar3,uVar6);
        iVar4 = FUN_0067c560(piVar1[0x1c],iVar4,uVar6);
        piVar1[0x1c] = iVar4;
        uVar3 = piVar1[0x20];
        piVar1[0x20] = uVar3 - uVar6;
        piVar1[0x21] = (piVar1[0x21] + (uint)(uVar2 < uVar5)) - (uint)(uVar3 < uVar6);
        local_10 = (uVar2 - uVar5) + local_10;
        if (local_14 == 1) {
          return -(uint)(local_10 != 0) & local_10;
        }
      } while (local_14 == 0);
LAB_004fb202:
      if (local_14 != 0) {
        local_10 = local_14;
      }
    }
  }
  return local_10;
}

