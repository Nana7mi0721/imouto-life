
void __thiscall FUN_00614050(int param_1,undefined4 param_2)

{
  int iVar1;
  float *pfVar2;
  float *pfVar3;
  char cVar4;
  uint uVar5;
  undefined4 uVar6;
  undefined4 *puVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  int iVar11;
  int iVar12;
  undefined4 *puVar13;
  int iVar14;
  int local_7c;
  int local_78;
  int local_74;
  int iStack_70;
  undefined4 local_68;
  undefined4 local_60;
  undefined1 local_5c [4];
  undefined4 local_58;
  undefined1 local_54 [8];
  undefined **local_4c;
  int local_48;
  undefined4 local_40 [4];
  undefined4 local_30;
  undefined4 local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20 [8];
  
  local_7c = param_1;
  FUN_00620ae0((*(int *)(param_1 + 0x70) * *(int *)(param_1 + 0x10)) / 100 + 1);
  if (*(int *)(param_1 + 0x7c) != 0) {
    iVar14 = (*(int *)(param_1 + 0x6c) * *(int *)(param_1 + 0x38)) / 100 + 1;
    FUN_00620ae0(iVar14);
    local_78 = 0;
    local_74 = *(int *)(param_1 + 0x7c) - iVar14;
    piVar10 = &local_78;
    if (-1 < local_74) {
      piVar10 = &local_74;
    }
    *(int *)(param_1 + 0x7c) = *piVar10;
  }
  uVar5 = *(int *)(param_1 + 0x68) + 1U & 0x80000001;
  if ((int)uVar5 < 0) {
    uVar5 = (uVar5 - 1 | 0xfffffffe) + 1;
  }
  *(uint *)(param_1 + 0x68) = uVar5;
  iVar14 = *(int *)(param_1 + 0x54 + uVar5 * 4);
  iVar9 = param_1;
  if (iVar14 != 0) {
    local_74 = param_1 + 0x2c;
    while( true ) {
      local_78 = *(int *)(iVar14 + 0x38);
      if (*(int *)(iVar14 + 0x34) == 0) {
        *(int *)(iVar9 + 0x54 + *(int *)(iVar14 + 0x3c) * 4) = local_78;
      }
      else {
        *(int *)(*(int *)(iVar14 + 0x34) + 0x38) = local_78;
      }
      if (*(int *)(iVar14 + 0x38) != 0) {
        *(undefined4 *)(*(int *)(iVar14 + 0x38) + 0x34) = *(undefined4 *)(iVar14 + 0x34);
      }
      *(undefined4 *)(iVar14 + 0x34) = 0;
      *(undefined4 *)(iVar14 + 0x38) = *(undefined4 *)(iVar9 + 0x5c);
      if (*(int *)(iVar9 + 0x5c) != 0) {
        *(int *)(*(int *)(iVar9 + 0x5c) + 0x34) = iVar14;
      }
      *(int *)(iVar9 + 0x5c) = iVar14;
      FUN_00621410(*(undefined4 *)(iVar14 + 0x30));
      local_40[0] = *(undefined4 *)(iVar14 + 0x10);
      local_40[1] = *(undefined4 *)(iVar14 + 0x14);
      local_40[2] = *(undefined4 *)(iVar14 + 0x18);
      local_40[3] = *(undefined4 *)(iVar14 + 0x1c);
      local_30 = *(undefined4 *)(iVar14 + 0x20);
      local_2c = *(undefined4 *)(iVar14 + 0x24);
      local_28 = *(undefined4 *)(iVar14 + 0x28);
      local_24 = *(undefined4 *)(iVar14 + 0x2c);
      puVar7 = local_40;
      puVar13 = local_20;
      for (iVar9 = 8; iVar9 != 0; iVar9 = iVar9 + -1) {
        *puVar13 = *puVar7;
        puVar7 = puVar7 + 1;
        puVar13 = puVar13 + 1;
      }
      uVar6 = FUN_00620f80(local_20,iVar14);
      *(undefined4 *)(iVar14 + 0x30) = uVar6;
      *(undefined4 *)(iVar14 + 0x3c) = 2;
      if (local_78 == 0) break;
      iVar14 = local_78;
      iVar9 = local_7c;
    }
    *(undefined1 *)(local_7c + 0x9a) = 1;
    *(undefined4 *)(local_7c + 0x7c) = *(undefined4 *)(local_7c + 0x38);
    iVar9 = local_7c;
  }
  local_4c = &PTR_LAB_008043c4;
  local_48 = iVar9;
  if (*(char *)(iVar9 + 0x99) != '\0') {
    iVar14 = *(int *)(param_1 + 4);
    local_74 = *(int *)(iVar9 + 0x2c);
    if ((iVar14 != 0) && (local_74 != 0)) {
      local_78 = 0x7c;
      FUN_00614d60(0x80,local_5c);
      piVar10 = *(int **)(param_1 + 0x24);
      *piVar10 = iVar14;
      piVar10[1] = local_74;
      iVar14 = 1;
      iVar9 = 8;
      do {
        iVar12 = iVar9 + -8;
        piVar10 = (int *)(iVar12 + *(int *)(param_1 + 0x24));
        iVar11 = iVar14 + -1;
        iVar8 = *piVar10;
        iStack_70 = piVar10[1];
        if (local_78 < iVar11) {
          FUN_00614d60(*(int *)(param_1 + 0x1c) << 1,local_54);
          local_78 = *(int *)(param_1 + 0x1c) + -4;
        }
        if (iVar8 == iStack_70) {
          if (*(int *)(iVar8 + 0x28) != 0) {
            uVar6 = *(undefined4 *)(iVar8 + 0x24);
            puVar7 = (undefined4 *)(iVar12 + *(int *)(param_1 + 0x24));
            *puVar7 = uVar6;
            puVar7[1] = uVar6;
            uVar6 = *(undefined4 *)(iVar8 + 0x28);
            puVar7 = (undefined4 *)(iVar9 + *(int *)(param_1 + 0x24));
            iVar11 = iVar14 + 2;
            *puVar7 = uVar6;
            puVar7[1] = uVar6;
            uVar6 = *(undefined4 *)(iVar8 + 0x28);
            iVar12 = iVar9 + 0x10;
            puVar7 = (undefined4 *)(iVar9 + 8 + *(int *)(param_1 + 0x24));
            *puVar7 = *(undefined4 *)(iVar8 + 0x24);
            puVar7[1] = uVar6;
          }
        }
        else {
          cVar4 = FUN_00614880(iVar8,iStack_70);
          if (cVar4 != '\0') {
            if (*(int *)(iVar8 + 0x28) == 0) {
              if (*(int *)(iStack_70 + 0x28) == 0) {
                (*(code *)local_4c[3])(iVar8,iStack_70);
              }
              else {
                iVar1 = *(int *)(iStack_70 + 0x24);
                piVar10 = (int *)(iVar12 + *(int *)(param_1 + 0x24));
                iVar11 = iVar14 + 1;
                *piVar10 = iVar8;
                piVar10[1] = iVar1;
                iVar14 = *(int *)(iStack_70 + 0x28);
                iVar12 = iVar9 + 8;
                piVar10 = (int *)(iVar9 + *(int *)(param_1 + 0x24));
                *piVar10 = iVar8;
                piVar10[1] = iVar14;
              }
            }
            else {
              if (*(int *)(iStack_70 + 0x28) == 0) {
                puVar7 = (undefined4 *)(iVar12 + *(int *)(param_1 + 0x24));
                *puVar7 = *(undefined4 *)(iVar8 + 0x24);
                puVar7[1] = iStack_70;
                uVar6 = *(undefined4 *)(iVar8 + 0x28);
                iVar8 = iStack_70;
              }
              else {
                local_68 = *(undefined4 *)(iStack_70 + 0x24);
                puVar7 = (undefined4 *)(iVar12 + *(int *)(param_1 + 0x24));
                *puVar7 = *(undefined4 *)(iVar8 + 0x24);
                puVar7[1] = local_68;
                local_60 = *(undefined4 *)(iStack_70 + 0x24);
                iVar11 = iVar9 + 8;
                puVar7 = (undefined4 *)(iVar9 + *(int *)(param_1 + 0x24));
                iVar14 = iVar14 + 2;
                *puVar7 = *(undefined4 *)(iVar8 + 0x28);
                puVar7[1] = local_60;
                local_58 = *(undefined4 *)(iStack_70 + 0x28);
                iVar9 = iVar9 + 0x10;
                puVar7 = (undefined4 *)(iVar11 + *(int *)(param_1 + 0x24));
                *puVar7 = *(undefined4 *)(iVar8 + 0x24);
                puVar7[1] = local_58;
                uVar6 = *(undefined4 *)(iVar8 + 0x28);
                iVar8 = *(int *)(iStack_70 + 0x28);
              }
              iVar11 = iVar14 + 1;
              iVar12 = iVar9 + 8;
              puVar7 = (undefined4 *)(iVar9 + *(int *)(param_1 + 0x24));
              *puVar7 = uVar6;
              puVar7[1] = iVar8;
            }
          }
        }
        iVar14 = iVar11;
        iVar9 = iVar12;
      } while (iVar12 != 0);
      iVar9 = local_7c;
    }
    if (*(char *)(iVar9 + 0x99) != '\0') {
      iVar14 = *(int *)(param_1 + 4);
      FUN_00614ad0(iVar14,iVar14,&local_4c);
    }
  }
  if (*(char *)(iVar9 + 0x9a) != '\0') {
    local_78 = (**(code **)(**(int **)(iVar9 + 0x60) + 0x18))();
    iVar14 = *(int *)(local_78 + 4);
    if (0 < iVar14) {
      local_74 = (*(int *)(iVar9 + 0x74) * iVar14) / 100;
      piVar10 = (int *)(iVar9 + 0x78);
      if (*(int *)(iVar9 + 0x78) <= local_74) {
        piVar10 = &local_74;
      }
      if (iVar14 < *piVar10) {
        piVar10 = &local_7c;
      }
      local_7c = *piVar10;
      iVar14 = 0;
      if (0 < local_7c) {
        do {
          piVar10 = (int *)(((*(int *)(iVar9 + 0x90) + iVar14) % *(int *)(local_78 + 4)) * 0x10 +
                           *(int *)(local_78 + 0xc));
          iVar8 = *piVar10;
          iVar11 = piVar10[1];
          pfVar2 = *(float **)(iVar8 + 0x30);
          pfVar3 = *(float **)(iVar11 + 0x30);
          if ((((pfVar3[4] < *pfVar2) || (pfVar2[4] < *pfVar3)) || (pfVar3[5] < pfVar2[1])) ||
             (((pfVar2[5] < pfVar3[1] || (pfVar3[6] < pfVar2[2])) || (pfVar2[6] < pfVar3[2])))) {
            (**(code **)(**(int **)(iVar9 + 0x60) + 8))(iVar8,iVar11,param_2);
            local_7c = local_7c + -1;
            iVar14 = iVar14 + -1;
          }
          iVar14 = iVar14 + 1;
        } while (iVar14 < local_7c);
      }
      if (*(int *)(local_78 + 4) < 1) {
        *(undefined4 *)(iVar9 + 0x90) = 0;
      }
      else {
        *(int *)(iVar9 + 0x90) = (*(int *)(iVar9 + 0x90) + local_7c) % *(int *)(local_78 + 4);
      }
    }
  }
  uVar5 = *(uint *)(iVar9 + 0x80);
  *(int *)(iVar9 + 0x8c) = *(int *)(iVar9 + 0x8c) + 1;
  *(undefined4 *)(iVar9 + 0x78) = 1;
  *(undefined1 *)(iVar9 + 0x9a) = 0;
  if (uVar5 == 0) {
    *(undefined4 *)(iVar9 + 0x88) = 0;
  }
  else {
    *(float *)(iVar9 + 0x88) = (float)*(uint *)(iVar9 + 0x84) / (float)(int)uVar5;
  }
  *(uint *)(iVar9 + 0x84) = *(uint *)(iVar9 + 0x84) >> 1;
  *(uint *)(iVar9 + 0x80) = uVar5 >> 1;
  return;
}

