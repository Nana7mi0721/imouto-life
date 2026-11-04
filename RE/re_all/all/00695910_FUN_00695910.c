
void FUN_00695910(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  int iVar8;
  char *pcVar9;
  int iStack_a2c;
  int *local_a28;
  int *piStack_a1c;
  int iStack_a18;
  char local_a0c [12];
  int aiStack_a00 [640];
  
  if (param_1[0x32] < 1) {
    *(undefined4 *)(*param_1 + 0x14) = 0x14;
    *(undefined4 *)(*param_1 + 0x18) = 0;
    (**(code **)*param_1)(param_1);
  }
  local_a28 = (int *)param_1[0x33];
  if ((local_a28[5] == 0) && (local_a28[6] == 0x3f)) {
    uVar5 = param_1[0x13];
    *(undefined1 *)(param_1 + 0x3f) = 0;
    if (0 < (int)uVar5) {
      pcVar9 = local_a0c;
      for (uVar4 = uVar5 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
        pcVar9[0] = '\0';
        pcVar9[1] = '\0';
        pcVar9[2] = '\0';
        pcVar9[3] = '\0';
        pcVar9 = pcVar9 + 4;
      }
      for (uVar5 = uVar5 & 3; uVar5 != 0; uVar5 = uVar5 - 1) {
        *pcVar9 = '\0';
        pcVar9 = pcVar9 + 1;
      }
    }
  }
  else {
    *(undefined1 *)(param_1 + 0x3f) = 1;
    if (0 < param_1[0x13]) {
      piVar7 = aiStack_a00;
      for (iVar6 = (param_1[0x13] & 0xffffffU) << 6; iVar6 != 0; iVar6 = iVar6 + -1) {
        *piVar7 = -1;
        piVar7 = piVar7 + 1;
      }
    }
  }
  iStack_a2c = 1;
  if (0 < param_1[0x32]) {
    do {
      iStack_a18 = *local_a28;
      if ((iStack_a18 < 1) || (4 < iStack_a18)) {
        *(undefined4 *)(*param_1 + 0x14) = 0x1b;
        *(int *)(*param_1 + 0x18) = iStack_a18;
        *(undefined4 *)(*param_1 + 0x1c) = 4;
        (**(code **)*param_1)(param_1);
      }
      iVar6 = 0;
      piVar7 = local_a28;
      if (0 < iStack_a18) {
        do {
          iVar1 = piVar7[1];
          if ((iVar1 < 0) || (param_1[0x13] <= iVar1)) {
            *(undefined4 *)(*param_1 + 0x14) = 0x14;
            *(int *)(*param_1 + 0x18) = iStack_a2c;
            (**(code **)*param_1)(param_1);
          }
          if ((0 < iVar6) && (iVar1 <= *piVar7)) {
            *(undefined4 *)(*param_1 + 0x14) = 0x14;
            *(int *)(*param_1 + 0x18) = iStack_a2c;
            (**(code **)*param_1)(param_1);
          }
          iVar6 = iVar6 + 1;
          piVar7 = piVar7 + 1;
        } while (iVar6 < iStack_a18);
      }
      iVar6 = local_a28[5];
      iVar1 = local_a28[6];
      iVar2 = local_a28[7];
      iVar3 = local_a28[8];
      if ((char)param_1[0x3f] == '\0') {
        if ((((iVar6 != 0) || (iVar1 != 0x3f)) || (iVar2 != 0)) || (iVar3 != 0)) {
          *(undefined4 *)(*param_1 + 0x14) = 0x12;
          *(int *)(*param_1 + 0x18) = iStack_a2c;
          (**(code **)*param_1)(param_1);
        }
        if (0 < iStack_a18) {
          piVar7 = local_a28;
          do {
            piVar7 = piVar7 + 1;
            iVar6 = *piVar7;
            if (local_a0c[iVar6] != '\0') {
              *(undefined4 *)(*param_1 + 0x14) = 0x14;
              *(int *)(*param_1 + 0x18) = iStack_a2c;
              (**(code **)*param_1)(param_1);
            }
            iStack_a18 = iStack_a18 + -1;
            local_a0c[iVar6] = '\x01';
          } while (iStack_a18 != 0);
        }
      }
      else {
        if (((((iVar6 < 0) || (0x3f < iVar6)) ||
             ((iVar1 < iVar6 || ((0x3f < iVar1 || (iVar2 < 0)))))) || (10 < iVar2)) ||
           ((iVar3 < 0 || (10 < iVar3)))) {
          *(undefined4 *)(*param_1 + 0x14) = 0x12;
          *(int *)(*param_1 + 0x18) = iStack_a2c;
          (**(code **)*param_1)(param_1);
        }
        if (iVar6 == 0) {
          if (iVar1 != 0) {
            *(undefined4 *)(*param_1 + 0x14) = 0x12;
            *(int *)(*param_1 + 0x18) = iStack_a2c;
            (**(code **)*param_1)(param_1);
          }
        }
        else if (iStack_a18 != 1) {
          *(undefined4 *)(*param_1 + 0x14) = 0x12;
          *(int *)(*param_1 + 0x18) = iStack_a2c;
          (**(code **)*param_1)(param_1);
        }
        if (0 < iStack_a18) {
          piStack_a1c = local_a28;
          do {
            piStack_a1c = piStack_a1c + 1;
            iVar8 = *piStack_a1c;
            if ((iVar6 != 0) && (aiStack_a00[iVar8 * 0x40] < 0)) {
              *(undefined4 *)(*param_1 + 0x14) = 0x12;
              *(int *)(*param_1 + 0x18) = iStack_a2c;
              (**(code **)*param_1)(param_1);
            }
            if (iVar6 <= iVar1) {
              piVar7 = aiStack_a00 + iVar8 * 0x40 + iVar6;
              iVar8 = (iVar1 - iVar6) + 1;
              do {
                if (*piVar7 < 0) {
                  if (iVar2 != 0) {
LAB_00695b76:
                    *(undefined4 *)(*param_1 + 0x14) = 0x12;
                    *(int *)(*param_1 + 0x18) = iStack_a2c;
                    (**(code **)*param_1)(param_1);
                  }
                }
                else if ((iVar2 != *piVar7) || (iVar3 != iVar2 + -1)) goto LAB_00695b76;
                *piVar7 = iVar3;
                piVar7 = piVar7 + 1;
                iVar8 = iVar8 + -1;
              } while (iVar8 != 0);
            }
            iStack_a18 = iStack_a18 + -1;
          } while (iStack_a18 != 0);
        }
      }
      local_a28 = local_a28 + 9;
      iStack_a2c = iStack_a2c + 1;
    } while (iStack_a2c <= param_1[0x32]);
  }
  if ((char)param_1[0x3f] == '\0') {
    iVar6 = 0;
    if (0 < param_1[0x13]) {
      do {
        if (local_a0c[iVar6] == '\0') {
          *(undefined4 *)(*param_1 + 0x14) = 0x2e;
          (**(code **)*param_1)(param_1);
        }
        iVar6 = iVar6 + 1;
      } while (iVar6 < param_1[0x13]);
    }
  }
  else {
    iVar6 = 0;
    if (0 < param_1[0x13]) {
      piVar7 = aiStack_a00;
      do {
        if (*piVar7 < 0) {
          *(undefined4 *)(*param_1 + 0x14) = 0x2e;
          (**(code **)*param_1)(param_1);
        }
        iVar6 = iVar6 + 1;
        piVar7 = piVar7 + 0x40;
      } while (iVar6 < param_1[0x13]);
      return;
    }
  }
  return;
}

