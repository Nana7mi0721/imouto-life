
undefined4
FUN_005be4a0(int param_1,int *param_2,int *param_3,undefined4 param_4,int param_5,int param_6,
            int param_7,int param_8,undefined4 param_9,int param_10,undefined4 param_11,
            undefined4 param_12,int param_13)

{
  char cVar1;
  byte bVar2;
  byte bVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  uint uVar7;
  undefined4 *puVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  char *unaff_EDI;
  int local_34;
  int local_20;
  int local_18;
  int local_14;
  undefined4 local_10;
  int local_c;
  int local_8;
  undefined4 local_4;
  
  cVar1 = *unaff_EDI;
  bVar2 = 0;
  iVar11 = 0;
  local_34 = 0;
  if (((cVar1 == '\x01') || (cVar1 == '\x03')) || (bVar4 = false, cVar1 == '\x05')) {
    bVar4 = true;
  }
  bVar3 = 0;
  bVar6 = false;
  bVar5 = false;
  if (!bVar4) {
    if ((param_7 < param_5) && (param_7 == param_3[2])) {
      bVar2 = 1;
      bVar6 = true;
    }
    if ((param_8 < param_6) && (param_8 == param_3[3])) {
      bVar3 = 1;
      bVar5 = true;
    }
    iVar11 = ((uint)bVar2 + param_7) * (uint)*(byte *)(param_10 + 4);
    iVar9 = ((uint)bVar3 + param_8) * iVar11;
    if (param_13 == 0) {
      iVar9 = FUN_005b89a0(iVar9);
      if (iVar9 < 0) {
        return 0xffffffff;
      }
      local_34 = DAT_00f2eaa8;
    }
    else {
      local_34 = FUN_0056e030(iVar9,
                              "..\\..\\..\\..\\Source\\Library\\Main\\Windows\\DxGraphicsD3D11.cpp",
                              0x55a4);
      if (local_34 == 0) {
        FUN_0056bca0(&DAT_007fd818);
        return 0xffffffff;
      }
    }
  }
  uVar7 = -(uint)(*(char *)(param_1 + 9) != '\0') & 5;
  local_20 = 0;
  if (uVar7 != 0xffffffff) {
    do {
      if ((((*param_3 == 0) && (param_3[2] == param_5)) && (param_3[1] == 0)) &&
         (param_3[3] == param_6)) {
        if (!bVar4) goto LAB_005be66d;
        local_8 = param_6;
        local_c = param_5;
        local_18 = 0;
        local_14 = 0;
        local_10 = 0;
        iVar9 = *(int *)(unaff_EDI + 0x42c) * *(int *)(unaff_EDI + 0x428) * (uint)(byte)unaff_EDI[5]
        ;
        local_4 = 1;
        FUN_005d52f0(param_4,local_20,&local_18,
                     ((int)(iVar9 + (iVar9 >> 0x1f & 7U)) >> 3) * local_20 +
                     *(int *)(unaff_EDI + 0x434),
                     ((int)((uint)(byte)unaff_EDI[5] * 4) >> 3) * param_5,0,param_13);
      }
      else if (!bVar4) {
LAB_005be66d:
        FUN_00549b20(local_34,iVar11,param_10,
                     *(int *)(unaff_EDI + 0x42c) * *(int *)(unaff_EDI + 0x430) * local_20 +
                     *(int *)(unaff_EDI + 0x434),*(int *)(unaff_EDI + 0x430));
        if (bVar5) {
          FUN_0056d420((param_8 - param_3[1]) * iVar11 + local_34,
                       ((param_8 - param_3[1]) + -1) * iVar11 + local_34,
                       (param_2[2] - *param_2) * (uint)*(byte *)(param_10 + 4));
        }
        if (bVar6) {
          iVar9 = param_2[3] - param_2[1];
          uVar10 = (uint)*(byte *)(param_10 + 4);
          puVar8 = (undefined4 *)((param_7 - *param_3) * uVar10 + local_34);
          if (uVar10 == 2) {
            if (0 < iVar9) {
              do {
                *(undefined2 *)puVar8 = *(undefined2 *)((int)puVar8 + -2);
                puVar8 = (undefined4 *)((int)puVar8 + iVar11);
                iVar9 = iVar9 + -1;
              } while (iVar9 != 0);
            }
          }
          else if ((uVar10 == 4) && (0 < iVar9)) {
            do {
              *puVar8 = puVar8[-1];
              puVar8 = (undefined4 *)((int)puVar8 + iVar11);
              iVar9 = iVar9 + -1;
            } while (iVar9 != 0);
          }
        }
        if ((bVar5) && (bVar6)) {
          uVar10 = (uint)*(byte *)(param_10 + 4);
          puVar8 = (undefined4 *)
                   ((param_7 - *param_3) * uVar10 + (param_8 - param_3[1]) * iVar11 + local_34);
          if (uVar10 == 2) {
            *(undefined2 *)puVar8 = *(undefined2 *)((int)puVar8 + (-2 - iVar11));
          }
          else if (uVar10 == 4) {
            *puVar8 = *(undefined4 *)((int)puVar8 + (-4 - iVar11));
          }
        }
        local_14 = param_3[1];
        local_18 = *param_3;
        local_c = param_3[2];
        local_8 = param_3[3];
        local_10 = 0;
        local_4 = 1;
        FUN_005d52f0(param_4,local_20,&local_18,local_34,iVar11,0,param_13);
      }
      else {
        FUN_0056bb10(&DAT_007fc5e0);
      }
      local_20 = local_20 + 1;
    } while (local_20 < (int)(uVar7 + 1));
  }
  if (((!bVar4) && (param_13 != 0)) && (local_34 != 0)) {
    FUN_0056e1d0(local_34);
  }
  return 0;
}

