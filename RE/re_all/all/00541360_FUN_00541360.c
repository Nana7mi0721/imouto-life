
undefined4 FUN_00541360(undefined4 *param_1,int param_2,int param_3)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  undefined2 uVar4;
  undefined4 uVar5;
  bool bVar6;
  bool bVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  byte *pbVar11;
  int iVar12;
  byte *pbVar13;
  byte *pbVar14;
  byte *pbVar15;
  uint uVar16;
  int iVar17;
  uint uVar18;
  uint uVar19;
  int local_78;
  undefined2 uStack_74;
  undefined2 uStack_70;
  byte *local_6c;
  undefined2 uStack_68;
  undefined4 uStack_64;
  undefined2 uStack_60;
  undefined4 uStack_5c;
  undefined2 uStack_58;
  char acStack_44 [2];
  byte bStack_42;
  undefined1 uStack_41;
  undefined1 uStack_40;
  undefined1 uStack_3f;
  undefined1 uStack_3e;
  byte bStack_3d;
  undefined1 uStack_3c;
  undefined1 uStack_3b;
  undefined1 uStack_3a;
  undefined1 uStack_39;
  undefined1 uStack_38;
  undefined1 uStack_37;
  undefined1 uStack_36;
  undefined1 uStack_35;
  byte bStack_34;
  byte bStack_33;
  byte *local_30;
  int iStack_2c;
  int iStack_28;
  uint uStack_24;
  uint uStack_20;
  undefined1 uStack_1c;
  undefined1 uStack_1b;
  undefined1 uStack_1a;
  undefined1 uStack_19;
  undefined1 auStack_14 [20];
  
  uVar5 = param_1[6];
  local_30 = (byte *)0x0;
  local_6c = (byte *)0x0;
  local_78 = 0;
  (*(code *)param_1[1])(uVar5,0xffffffe6,0xffffffff,2);
  iVar8 = (*(code *)param_1[2])(&uStack_1c,0x1a,1,uVar5);
  if ((iVar8 == 1) &&
     (iVar8 = FUN_0056d3d0(s_TRUEVISION_XFILE__0084d110,auStack_14,0x12), iVar8 == 0)) {
    uStack_5c = CONCAT13(uStack_19,CONCAT12(uStack_1a,CONCAT11(uStack_1b,uStack_1c)));
    if (uStack_5c != 0) goto LAB_005413e8;
    iStack_2c = 1;
    (*(code *)param_1[1])(uVar5,0,0,0);
  }
  else {
LAB_005413e8:
    iStack_2c = 0;
    (*(code *)param_1[1])(uVar5,0,0,0);
  }
  iVar8 = (*(code *)param_1[2])(acStack_44,0x12,1,uVar5);
  if (iVar8 != 1) {
    return 0xffffffff;
  }
  uStack_58 = CONCAT11(uStack_40,uStack_41);
  uStack_64._0_2_ = CONCAT11(uStack_3e,uStack_3f);
  uStack_60 = CONCAT11(uStack_3b,uStack_3c);
  uStack_70 = CONCAT11(uStack_39,uStack_3a);
  uStack_74 = CONCAT11(uStack_37,uStack_38);
  uStack_68 = CONCAT11(uStack_35,uStack_36);
  if (acStack_44[0] != '\0') {
    (*(code *)param_1[1])(uVar5,acStack_44[0],0,1);
  }
  if ((bStack_42 == 1) || (bStack_42 == 9)) {
    bVar7 = true;
  }
  else {
    bVar7 = false;
    bStack_3d = bStack_34;
  }
  uVar9 = (uint)bStack_3d;
  if ((3 < bStack_42) && (bStack_42 < 9)) {
    return 0xffffffff;
  }
  if (0xb < bStack_42) {
    return 0xffffffff;
  }
  if (uStack_60 != 0) {
    return 0xffffffff;
  }
  if (uStack_70 != 0) {
    return 0xffffffff;
  }
  if (0x8000 < uStack_74) {
    return 0xffffffff;
  }
  if (0x8000 < uStack_68) {
    return 0xffffffff;
  }
  if (((uVar9 != 0x10) && (uVar9 != 0x18)) && (uVar9 != 0x20)) {
    return 0xffffffff;
  }
  if (bStack_42 == 0) {
    return 0xffffffff;
  }
  if (bStack_42 == 3) {
    return 0xffffffff;
  }
  if (bStack_42 == 0xb) {
    return 0xffffffff;
  }
  bVar6 = false;
  switch(bStack_42) {
  case 0:
  case 1:
  case 2:
  case 3:
    bVar6 = false;
    break;
  case 9:
  case 10:
    bVar6 = true;
  }
  uVar18 = (uint)uStack_68;
  uStack_20 = bStack_33 >> 4 & 1;
  uStack_24 = ~(uint)(bStack_33 >> 5) & 1;
  iVar10 = (int)uVar9 >> 3;
  uVar16 = (uint)uStack_74;
  iVar8 = iVar10 * uVar16;
  iVar17 = iVar8 * uVar18;
  *(uint *)(param_2 + 0x428) = uVar16;
  *(uint *)(param_2 + 0x42c) = uVar18;
  *(int *)(param_2 + 0x430) = iVar8;
  *(byte *)(param_2 + 5) = bStack_3d;
  *(char *)(param_2 + 4) = (char)iVar10;
  if (uVar9 == 0x10) {
    *(undefined1 *)(param_2 + 8) = 5;
    *(undefined1 *)(param_2 + 9) = 5;
    *(undefined1 *)(param_2 + 0xd) = 5;
    *(undefined1 *)(param_2 + 10) = 5;
    *(undefined1 *)(param_2 + 0xc) = 10;
    *(undefined4 *)(param_2 + 0x10) = 0x7c00;
    *(undefined4 *)(param_2 + 0x14) = 0x3e0;
    *(undefined4 *)(param_2 + 0x18) = 0x1f;
    *(undefined4 *)(param_2 + 0x20) = 0x8000;
LAB_005416ba:
    *(undefined4 *)(param_2 + 0x1c) = 0;
    *(undefined1 *)(param_2 + 0xf) = 0;
    *(undefined1 *)(param_2 + 0xb) = 0;
LAB_005416c5:
    *(undefined1 *)(param_2 + 0xe) = 0;
  }
  else {
    if (uVar9 == 0x18) {
      *(undefined1 *)(param_2 + 8) = 8;
      *(undefined1 *)(param_2 + 0xc) = 0x10;
      *(undefined4 *)(param_2 + 0x10) = 0xff0000;
      *(undefined1 *)(param_2 + 9) = 8;
      *(undefined1 *)(param_2 + 0xd) = 8;
      *(undefined4 *)(param_2 + 0x14) = 0xff00;
      *(undefined1 *)(param_2 + 10) = 8;
      *(undefined4 *)(param_2 + 0x18) = 0xff;
      *(undefined4 *)(param_2 + 0x20) = 0;
      goto LAB_005416ba;
    }
    if (uVar9 == 0x20) {
      *(undefined1 *)(param_2 + 8) = 8;
      *(undefined1 *)(param_2 + 0xc) = 0x10;
      *(undefined4 *)(param_2 + 0x10) = 0xff0000;
      *(undefined1 *)(param_2 + 9) = 8;
      *(undefined1 *)(param_2 + 0xd) = 8;
      *(undefined4 *)(param_2 + 0x14) = 0xff00;
      *(undefined1 *)(param_2 + 10) = 8;
      *(undefined4 *)(param_2 + 0x18) = 0xff;
      *(undefined1 *)(param_2 + 0xb) = 8;
      *(undefined1 *)(param_2 + 0xf) = 0x18;
      *(undefined4 *)(param_2 + 0x1c) = 0xff000000;
      *(undefined4 *)(param_2 + 0x20) = 0;
      goto LAB_005416c5;
    }
  }
  if (param_3 != 0) {
    *(undefined4 *)(param_2 + 0x434) = 0;
    return 0;
  }
  iStack_28 = iVar8;
  pbVar11 = (byte *)FUN_0056e030(iVar17,"..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",
                                 0x1028);
  if (pbVar11 == (byte *)0x0) {
    return 0xffffffff;
  }
  if (bVar7) {
    local_78 = FUN_0056e030(iVar10 << 8,"..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",
                            0x1031);
    if (local_78 == 0) goto LAB_00541cae;
    FUN_0056d380(local_78,0,iVar10 << 8);
    iVar8 = (*(code *)param_1[2])
                      ((uint)uStack_58 * iVar10 + local_78,(uint)(ushort)uStack_64 * iVar10,1,uVar5)
    ;
    if (iVar8 == 0) goto LAB_00541cae;
    if (bVar6) {
      uStack_64 = uVar18 * uVar16;
      iVar8 = (*(code *)*param_1)(uVar5);
      (*(code *)param_1[1])(uVar5,0xffffffe6,0xffffffff,2);
      iVar12 = (*(code *)*param_1)(uVar5);
      (*(code *)param_1[1])(uVar5,iVar8,0,0);
      local_6c = (byte *)FUN_0056e030(iVar12 - iVar8,
                                      "..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",
                                      0x1087);
      if ((local_6c == (byte *)0x0) ||
         (iVar8 = (*(code *)param_1[2])(local_6c,iVar12 - iVar8,1,uVar5), iVar8 == 0))
      goto LAB_00541cae;
      if (uVar9 == 0x10) {
        pbVar13 = local_6c;
        pbVar15 = pbVar11;
        do {
          iVar8 = (*pbVar13 & 0x7f) + 1;
          uStack_64 = uStack_64 - iVar8;
          pbVar14 = pbVar13 + 1;
          if ((*pbVar13 & 0x80) == 0) {
            do {
              *(undefined2 *)pbVar15 = *(undefined2 *)(local_78 + (uint)*pbVar14 * 2);
              pbVar15 = pbVar15 + 2;
              pbVar14 = pbVar14 + 1;
              iVar8 = iVar8 + -1;
            } while (iVar8 != 0);
          }
          else {
            uVar4 = *(undefined2 *)(local_78 + (uint)*pbVar14 * 2);
            pbVar14 = pbVar13 + 2;
            do {
              *(undefined2 *)pbVar15 = uVar4;
              pbVar15 = pbVar15 + 2;
              iVar8 = iVar8 + -1;
            } while (iVar8 != 0);
          }
          pbVar13 = pbVar14;
        } while (uStack_64 != 0);
      }
      else if (uVar9 == 0x18) {
        pbVar13 = local_6c;
        pbVar15 = pbVar11;
        do {
          iVar8 = (*pbVar13 & 0x7f) + 1;
          uStack_64 = uStack_64 - iVar8;
          pbVar14 = pbVar13 + 1;
          if ((*pbVar13 & 0x80) == 0) {
            do {
              *pbVar15 = *(byte *)(local_78 + (uint)*pbVar14 * 3);
              pbVar15[1] = *(byte *)((uint)*pbVar14 * 3 + 1 + local_78);
              pbVar15[2] = *(byte *)((uint)*pbVar14 * 3 + 2 + local_78);
              pbVar15 = pbVar15 + 3;
              pbVar13 = pbVar14 + 1;
              iVar8 = iVar8 + -1;
              pbVar14 = pbVar13;
            } while (iVar8 != 0);
          }
          else {
            uVar19 = (uint)pbVar13[1];
            iVar12 = local_78 + uVar19 * 2;
            bVar1 = *(byte *)(uVar19 + 1 + iVar12);
            pbVar14 = (byte *)(uVar19 + iVar12);
            bVar2 = *pbVar14;
            bVar3 = pbVar14[2];
            do {
              pbVar15[1] = bVar1;
              *pbVar15 = bVar2;
              pbVar15[2] = bVar3;
              pbVar15 = pbVar15 + 3;
              iVar8 = iVar8 + -1;
            } while (iVar8 != 0);
            pbVar13 = pbVar13 + 2;
          }
        } while (uStack_64 != 0);
      }
      else if (uVar9 == 0x20) {
        pbVar13 = local_6c;
        pbVar15 = pbVar11;
        do {
          iVar8 = (*pbVar13 & 0x7f) + 1;
          uStack_64 = uStack_64 - iVar8;
          pbVar14 = pbVar13 + 1;
          if ((*pbVar13 & 0x80) == 0) {
            do {
              *(undefined4 *)pbVar15 = *(undefined4 *)(local_78 + (uint)*pbVar14 * 4);
              pbVar15 = pbVar15 + 4;
              pbVar14 = pbVar14 + 1;
              iVar8 = iVar8 + -1;
            } while (iVar8 != 0);
          }
          else {
            uVar5 = *(undefined4 *)(local_78 + (uint)*pbVar14 * 4);
            pbVar14 = pbVar13 + 2;
            do {
              *(undefined4 *)pbVar15 = uVar5;
              pbVar15 = pbVar15 + 4;
              iVar8 = iVar8 + -1;
            } while (iVar8 != 0);
          }
          pbVar13 = pbVar14;
        } while (uStack_64 != 0);
      }
    }
    else {
      iVar8 = uVar18 * uVar16;
      local_6c = (byte *)FUN_0056e030(iVar8,"..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp"
                                      ,0x1042);
      if ((local_6c == (byte *)0x0) ||
         (iVar12 = (*(code *)param_1[2])(local_6c,iVar8,1,uVar5), iVar12 == 0)) goto LAB_00541cae;
      if (uVar9 == 0x10) {
        pbVar13 = local_6c;
        pbVar15 = pbVar11;
        do {
          *(undefined2 *)pbVar15 = *(undefined2 *)(local_78 + (uint)*pbVar13 * 2);
          pbVar15 = pbVar15 + 2;
          pbVar13 = pbVar13 + 1;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      else if (uVar9 == 0x18) {
        pbVar15 = pbVar11 + 2;
        pbVar13 = local_6c;
        do {
          pbVar15[-2] = *(byte *)(local_78 + (uint)*pbVar13 * 3);
          pbVar15[-1] = *(byte *)((uint)*pbVar13 * 3 + 1 + local_78);
          *pbVar15 = *(byte *)((uint)*pbVar13 * 3 + 2 + local_78);
          pbVar15 = pbVar15 + 3;
          pbVar13 = pbVar13 + 1;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
      else if (uVar9 == 0x20) {
        pbVar13 = local_6c;
        pbVar15 = pbVar11;
        do {
          *(undefined4 *)pbVar15 = *(undefined4 *)(local_78 + (uint)*pbVar13 * 4);
          pbVar15 = pbVar15 + 4;
          pbVar13 = pbVar13 + 1;
          iVar8 = iVar8 + -1;
        } while (iVar8 != 0);
      }
    }
    FUN_0056e1d0(local_6c);
    FUN_0056e1d0(local_78);
LAB_00541c67:
    iVar8 = iStack_28;
  }
  else {
    if (bVar6) {
      iVar8 = (*(code *)*param_1)(uVar5);
      (*(code *)param_1[1])
                (uVar5,-(uint)(iStack_2c != 0) & 0xffffffe6,(int)-(uint)(iStack_2c != 0) >> 0x1f,2);
      iVar12 = (*(code *)*param_1)(uVar5);
      (*(code *)param_1[1])(uVar5,iVar8,iVar8 >> 0x1f,0);
      local_6c = (byte *)FUN_0056e030(iVar12 - iVar8,
                                      "..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",
                                      0x110c);
      if ((local_6c == (byte *)0x0) ||
         (iVar8 = (*(code *)param_1[2])(local_6c,iVar12 - iVar8,1,uVar5), iVar8 == 0))
      goto LAB_00541cae;
      iVar8 = uVar18 * uVar16;
      pbVar13 = local_6c;
      pbVar15 = pbVar11;
      if (bStack_34 == 0x10) {
        do {
          iVar12 = (*pbVar13 & 0x7f) + 1;
          iVar8 = iVar8 - iVar12;
          pbVar14 = pbVar13 + 1;
          if ((char)*pbVar13 < '\0') {
            do {
              *pbVar15 = pbVar13[1];
              pbVar15[1] = pbVar13[2];
              pbVar15 = pbVar15 + 2;
              iVar12 = iVar12 + -1;
            } while (iVar12 != 0);
            pbVar13 = pbVar13 + 3;
          }
          else {
            do {
              *pbVar15 = *pbVar14;
              pbVar15[1] = pbVar14[1];
              pbVar15 = pbVar15 + 2;
              pbVar13 = pbVar14 + 2;
              iVar12 = iVar12 + -1;
              pbVar14 = pbVar13;
            } while (iVar12 != 0);
          }
        } while (iVar8 != 0);
      }
      else if (bStack_34 == 0x18) {
        do {
          iVar12 = (*pbVar13 & 0x7f) + 1;
          iVar8 = iVar8 - iVar12;
          pbVar14 = pbVar13 + 1;
          if ((*pbVar13 & 0x80) == 0) {
            do {
              *pbVar15 = *pbVar14;
              pbVar15[1] = pbVar14[1];
              pbVar15[2] = pbVar14[2];
              pbVar15 = pbVar15 + 3;
              pbVar13 = pbVar14 + 3;
              iVar12 = iVar12 + -1;
              pbVar14 = pbVar13;
            } while (iVar12 != 0);
          }
          else {
            do {
              *pbVar15 = pbVar13[1];
              pbVar15[1] = pbVar13[2];
              pbVar15[2] = pbVar13[3];
              pbVar15 = pbVar15 + 3;
              iVar12 = iVar12 + -1;
            } while (iVar12 != 0);
            pbVar13 = pbVar13 + 4;
          }
        } while (iVar8 != 0);
      }
      else if (bStack_34 == 0x20) {
        do {
          iVar12 = (*pbVar13 & 0x7f) + 1;
          iVar8 = iVar8 - iVar12;
          pbVar14 = pbVar13 + 1;
          if ((*pbVar13 & 0x80) == 0) {
            do {
              *pbVar15 = *pbVar14;
              pbVar15[1] = pbVar14[1];
              pbVar15[2] = pbVar14[2];
              pbVar15[3] = pbVar14[3];
              pbVar15 = pbVar15 + 4;
              pbVar13 = pbVar14 + 4;
              iVar12 = iVar12 + -1;
              pbVar14 = pbVar13;
            } while (iVar12 != 0);
          }
          else {
            do {
              *pbVar15 = pbVar13[1];
              pbVar15[1] = pbVar13[2];
              pbVar15[2] = pbVar13[3];
              pbVar15[3] = pbVar13[4];
              pbVar15 = pbVar15 + 4;
              iVar12 = iVar12 + -1;
            } while (iVar12 != 0);
            pbVar13 = pbVar13 + 5;
          }
        } while (iVar8 != 0);
      }
      FUN_0056e1d0(local_6c);
      goto LAB_00541c67;
    }
    iVar12 = (*(code *)param_1[2])(pbVar11,iVar17,1);
    if (iVar12 == 0) goto LAB_00541cae;
  }
  uVar19 = uStack_20;
  local_6c = (byte *)0x0;
  local_78 = 0;
  if ((uStack_20 == 0) && (uStack_24 == 0)) {
    *(byte **)(param_2 + 0x434) = pbVar11;
    return 0;
  }
  local_30 = (byte *)FUN_0056e030(iVar17,"..\\..\\..\\..\\Source\\Library\\Main\\DxBaseImage.cpp",
                                  0x117f);
  if (local_30 != (byte *)0x0) {
    pbVar13 = local_30;
    if (uVar19 != 0) {
      pbVar13 = local_30 + (uVar16 - 1) * iVar10;
      iVar10 = -iVar10;
    }
    local_78 = 0;
    if (uStack_24 == 0) {
      if (uVar19 == 0) {
        local_78 = iVar8 * 2;
      }
    }
    else {
      pbVar13 = pbVar13 + (uVar18 - 1) * iVar8;
      if (uVar19 == 0) {
        local_78 = iVar8 * -2;
      }
    }
    pbVar15 = pbVar11;
    if (uVar9 == 0x10) {
      for (; uVar9 = uVar16, uVar18 != 0; uVar18 = uVar18 - 1) {
        for (; uVar9 != 0; uVar9 = uVar9 - 1) {
          *pbVar13 = *pbVar15;
          pbVar14 = pbVar15 + 1;
          pbVar15 = pbVar15 + 2;
          pbVar13[1] = *pbVar14;
          pbVar13 = pbVar13 + iVar10;
        }
        pbVar13 = pbVar13 + local_78;
      }
    }
    else if (uVar9 == 0x18) {
      for (; uVar9 = uVar16, uVar18 != 0; uVar18 = uVar18 - 1) {
        for (; uVar9 != 0; uVar9 = uVar9 - 1) {
          *pbVar13 = *pbVar15;
          pbVar13[1] = pbVar15[1];
          pbVar14 = pbVar15 + 2;
          pbVar15 = pbVar15 + 3;
          pbVar13[2] = *pbVar14;
          pbVar13 = pbVar13 + iVar10;
        }
        pbVar13 = pbVar13 + local_78;
      }
    }
    else if (uVar9 == 0x20) {
      for (; uVar9 = uVar16, uVar18 != 0; uVar18 = uVar18 - 1) {
        for (; uVar9 != 0; uVar9 = uVar9 - 1) {
          *pbVar13 = *pbVar15;
          pbVar13[1] = pbVar15[1];
          pbVar13[2] = pbVar15[2];
          pbVar14 = pbVar15 + 3;
          pbVar15 = pbVar15 + 4;
          pbVar13[3] = *pbVar14;
          pbVar13 = pbVar13 + iVar10;
        }
        pbVar13 = pbVar13 + local_78;
      }
    }
    *(byte **)(param_2 + 0x434) = local_30;
    FUN_0056e1d0(pbVar11);
    return 0;
  }
LAB_00541cae:
  FUN_0056e1d0(pbVar11);
  if (local_30 != (byte *)0x0) {
    FUN_0056e1d0(local_30);
  }
  if (local_78 != 0) {
    FUN_0056e1d0(local_78);
  }
  if (local_6c != (byte *)0x0) {
    FUN_0056e1d0(local_6c);
  }
  return 0xffffffff;
}

