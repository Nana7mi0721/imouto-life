
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_0056a470(int param_1)

{
  int *piVar1;
  ushort uVar2;
  ushort uVar3;
  undefined *puVar4;
  short sVar5;
  ushort uVar6;
  int iVar7;
  DWORD DVar8;
  int iVar9;
  byte bVar10;
  uint uVar11;
  short sVar12;
  uint unaff_EBX;
  int iVar13;
  int *piVar14;
  uint uVar15;
  int iVar16;
  undefined4 uVar17;
  byte bVar18;
  undefined4 uStack_94;
  undefined4 uStack_90;
  undefined4 uStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  undefined4 uStack_70;
  undefined4 uStack_6c;
  undefined4 uStack_68;
  undefined1 uStack_64;
  undefined1 uStack_63;
  undefined1 uStack_62;
  undefined1 uStack_61;
  undefined1 uStack_60;
  undefined1 uStack_5f;
  undefined1 uStack_5e;
  undefined1 uStack_5d;
  undefined1 uStack_5c;
  undefined1 uStack_5b;
  undefined1 uStack_5a;
  undefined1 uStack_59;
  undefined1 uStack_58;
  undefined1 uStack_57;
  undefined1 uStack_56;
  undefined1 uStack_55;
  undefined1 uStack_54;
  undefined1 uStack_53;
  undefined1 uStack_52;
  undefined1 uStack_51;
  undefined1 uStack_50;
  undefined1 uStack_4f;
  undefined1 uStack_4e;
  undefined1 uStack_4d;
  undefined1 uStack_4c;
  undefined1 uStack_4b;
  undefined1 uStack_4a;
  undefined1 uStack_49;
  undefined1 uStack_48;
  undefined1 uStack_47;
  undefined1 uStack_46;
  undefined1 uStack_45;
  uint uStack_34;
  uint uStack_30;
  uint uStack_2c;
  uint uStack_28;
  uint uStack_24;
  uint uStack_1c;
  
  iVar13 = param_1 * 0x4d4;
  piVar14 = (int *)(&DAT_00a74b84 + iVar13);
  if (DAT_00a828a0 == 1) {
    iVar7 = (*DAT_00aba168)();
    if (*piVar14 == iVar7) {
      return 0;
    }
    *piVar14 = iVar7;
    FUN_0056d380(&uStack_34,0,0x34);
    uStack_34 = 0x34;
    uStack_30 = 0xff;
    iVar7 = (*DAT_00aba170)(param_1,&uStack_34);
    if (iVar7 != 0) {
      uVar17 = 0x50;
      puVar4 = &DAT_00a74bcc;
LAB_0056af15:
      FUN_0056d380(puVar4 + iVar13,0,uVar17);
      (&DAT_00a74bf8)[param_1 * 0x135] = 0xffffffff;
      (&DAT_00a74bf4)[param_1 * 0x135] = 0xffffffff;
      (&DAT_00a74bf0)[param_1 * 0x135] = 0xffffffff;
      (&DAT_00a74bec)[param_1 * 0x135] = 0xffffffff;
      return 0;
    }
    if (uStack_34 == 0) {
      *(undefined4 *)(&DAT_00a74bcc + iVar13) = 0xfffffc18;
    }
    else if (uStack_34 == 0x7fff) {
LAB_0056a55a:
      *(undefined4 *)(&DAT_00a74bcc + iVar13) = 0;
    }
    else if (uStack_34 == 0xffff) {
      *(undefined4 *)(&DAT_00a74bcc + iVar13) = 1000;
    }
    else {
      uVar11 = ((&DAT_00a74bc8)[param_1 * 0x135] & 0x1ffff) >> 1;
      uVar15 = 0x8000 - uVar11;
      if (uStack_34 < uVar15) {
        *(uint *)(&DAT_00a74bcc + iVar13) = -(((uVar15 - uStack_34) * 1000) / uVar15);
      }
      else {
        if (uStack_34 <= uVar11 + 0x8000) goto LAB_0056a55a;
        *(uint *)(&DAT_00a74bcc + iVar13) = ((uStack_34 - uVar11) * 1000 + 0xfe0c0000) / uVar15;
      }
    }
    if (uStack_30 == 0) {
      *(undefined4 *)(&DAT_00a74bd0 + iVar13) = 0xfffffc18;
    }
    else if (uStack_30 == 0x7fff) {
LAB_0056a5ce:
      *(undefined4 *)(&DAT_00a74bd0 + iVar13) = 0;
    }
    else if (uStack_30 == 0xffff) {
      *(undefined4 *)(&DAT_00a74bd0 + iVar13) = 1000;
    }
    else {
      uVar11 = ((&DAT_00a74bc8)[param_1 * 0x135] & 0x1ffff) >> 1;
      uVar15 = 0x8000 - uVar11;
      if (uStack_30 < uVar15) {
        *(uint *)(&DAT_00a74bd0 + iVar13) = -(((uVar15 - uStack_30) * 1000) / uVar15);
      }
      else {
        if (uStack_30 <= uVar11 + 0x8000) goto LAB_0056a5ce;
        *(uint *)(&DAT_00a74bd0 + iVar13) = ((uStack_30 - uVar11) * 1000 + 0xfe0c0000) / uVar15;
      }
    }
    if ((&DAT_00a74c44)[param_1 * 0x135] == 0) {
      *(undefined4 *)(&DAT_00a74bd4 + iVar13) = 0;
      *(undefined4 *)(&DAT_00a74be0 + iVar13) = 0;
    }
    else {
      if (uStack_2c == 0) {
        *(undefined4 *)(&DAT_00a74bd4 + iVar13) = 0xfffffc18;
      }
      else if (uStack_2c == 0x7fff) {
LAB_0056a651:
        *(undefined4 *)(&DAT_00a74bd4 + iVar13) = 0;
      }
      else if (uStack_2c == 0xffff) {
        *(undefined4 *)(&DAT_00a74bd4 + iVar13) = 1000;
      }
      else {
        uVar11 = ((&DAT_00a74bc8)[param_1 * 0x135] & 0x1ffff) >> 1;
        uVar15 = 0x8000 - uVar11;
        if (uStack_2c < uVar15) {
          *(uint *)(&DAT_00a74bd4 + iVar13) = -(((uVar15 - uStack_2c) * 1000) / uVar15);
        }
        else {
          if (uStack_2c <= uVar11 + 0x8000) goto LAB_0056a651;
          *(uint *)(&DAT_00a74bd4 + iVar13) = ((uStack_2c - uVar11) * 1000 + 0xfe0c0000) / uVar15;
        }
      }
      if (uStack_28 == 0) {
        *(undefined4 *)(&DAT_00a74be0 + iVar13) = 0xfffffc18;
      }
      else if (uStack_28 == 0x7fff) {
LAB_0056a6c8:
        *(undefined4 *)(&DAT_00a74be0 + iVar13) = 0;
      }
      else if (uStack_28 == 0xffff) {
        *(undefined4 *)(&DAT_00a74be0 + iVar13) = 1000;
      }
      else {
        uVar11 = ((&DAT_00a74bc8)[param_1 * 0x135] & 0x1ffff) >> 1;
        uVar15 = 0x8000 - uVar11;
        if (uStack_28 < uVar15) {
          *(uint *)(&DAT_00a74be0 + iVar13) = -(((uVar15 - uStack_28) * 1000) / uVar15);
        }
        else {
          if (uStack_28 <= uVar11 + 0x8000) goto LAB_0056a6c8;
          *(uint *)(&DAT_00a74be0 + iVar13) = ((uStack_28 - uVar11) * 1000 + 0xfe0c0000) / uVar15;
        }
      }
      if (uStack_24 == 0) {
        *(undefined4 *)(&DAT_00a74bd8 + iVar13) = 0xfffffc18;
        goto LAB_0056a74d;
      }
      if (uStack_24 != 0x7fff) {
        if (uStack_24 == 0xffff) {
          *(undefined4 *)(&DAT_00a74bd8 + iVar13) = 1000;
          goto LAB_0056a74d;
        }
        uVar11 = ((&DAT_00a74bc8)[param_1 * 0x135] & 0x1ffff) >> 1;
        uVar15 = 0x8000 - uVar11;
        if (uStack_24 < uVar15) {
          *(uint *)(&DAT_00a74bd8 + iVar13) = -(((uVar15 - uStack_24) * 1000) / uVar15);
          goto LAB_0056a74d;
        }
        if (uVar11 + 0x8000 < uStack_24) {
          *(uint *)(&DAT_00a74bd8 + iVar13) = ((uStack_24 - uVar11) * 1000 + 0xfe0c0000) / uVar15;
          goto LAB_0056a74d;
        }
      }
    }
    *(undefined4 *)(&DAT_00a74bd8 + iVar13) = 0;
LAB_0056a74d:
    iVar7 = 0;
    do {
      bVar10 = (byte)iVar7;
      iVar7 = iVar7 + 1;
      *(byte *)(iVar13 + 0xa74bfb + iVar7) = -((1 << (bVar10 & 0x1f) & uStack_1c) != 0) & 0x80;
    } while (iVar7 < 0x18);
    return 0;
  }
  if ((int)(&DAT_00a74c38)[param_1 * 0x135] < 0) {
    iVar7 = (*DAT_00aba168)();
    if ((*piVar14 == iVar7) &&
       (DVar8 = WaitForSingleObject((HANDLE)(&DAT_00a74c40)[param_1 * 0x135],0), DVar8 != 0)) {
      return 0;
    }
    piVar1 = (int *)(&DAT_00a74c3c)[param_1 * 0x135];
    *piVar14 = iVar7;
    (**(code **)(*piVar1 + 100))(piVar1);
    iVar7 = (**(code **)(*(int *)(&DAT_00a74c3c)[param_1 * 0x135] + 0x24))
                      ((int *)(&DAT_00a74c3c)[param_1 * 0x135],0x50,&uStack_88);
    if (iVar7 != 0) {
      iVar9 = FUN_005501a0();
      if ((iVar9 != 0) || (DAT_00a828ac == 0)) {
        return 0xffffffff;
      }
      iVar9 = (**(code **)(*(int *)(&DAT_00a74c3c)[param_1 * 0x135] + 0x1c))
                        ((int *)(&DAT_00a74c3c)[param_1 * 0x135]);
      if (iVar9 == 0) {
        iVar7 = FUN_005501a0();
        if (iVar7 != 0) {
          return 0xffffffff;
        }
        if (DAT_00a828ac == 0) {
          return 0xffffffff;
        }
        iVar7 = (**(code **)(*(int *)(&DAT_00a74c3c)[param_1 * 0x135] + 0x24))
                          ((int *)(&DAT_00a74c3c)[param_1 * 0x135],0x50,&uStack_94);
      }
      if (iVar7 != 0) goto LAB_0056a9dc;
    }
    *(undefined4 *)(&DAT_00a74bcc + iVar13) = uStack_94;
    *(undefined4 *)(&DAT_00a74bd0 + iVar13) = uStack_90;
    *(undefined4 *)(&DAT_00a74bd8 + iVar13) = uStack_88;
    *(undefined4 *)(&DAT_00a74bd4 + iVar13) = uStack_8c;
    *(undefined4 *)(&DAT_00a74bdc + iVar13) = uStack_84;
    *(undefined4 *)(&DAT_00a74be4 + iVar13) = uStack_7c;
    *(undefined4 *)(&DAT_00a74be0 + iVar13) = uStack_80;
    *(undefined4 *)(&DAT_00a74be8 + iVar13) = uStack_78;
    (&DAT_00a74bf0)[param_1 * 0x135] = uStack_70;
    (&DAT_00a74bec)[param_1 * 0x135] = uStack_74;
    (&DAT_00a74bf4)[param_1 * 0x135] = uStack_6c;
    (&DAT_00a74bf8)[param_1 * 0x135] = uStack_68;
    (&DAT_00a74bfc)[iVar13] = uStack_64;
    (&DAT_00a74bfd)[iVar13] = uStack_63;
    (&DAT_00a74bfe)[iVar13] = uStack_62;
    (&DAT_00a74bff)[iVar13] = uStack_61;
    (&DAT_00a74c00)[iVar13] = uStack_60;
    (&DAT_00a74c01)[iVar13] = uStack_5f;
    (&DAT_00a74c02)[iVar13] = uStack_5e;
    (&DAT_00a74c03)[iVar13] = uStack_5d;
    (&DAT_00a74c04)[iVar13] = uStack_5c;
    (&DAT_00a74c05)[iVar13] = uStack_5b;
    (&DAT_00a74c06)[iVar13] = uStack_5a;
    (&DAT_00a74c07)[iVar13] = uStack_59;
    (&DAT_00a74c08)[iVar13] = uStack_58;
    (&DAT_00a74c09)[iVar13] = uStack_57;
    (&DAT_00a74c0a)[iVar13] = uStack_56;
    (&DAT_00a74c0b)[iVar13] = uStack_55;
    (&DAT_00a74c0c)[iVar13] = uStack_54;
    (&DAT_00a74c0d)[iVar13] = uStack_53;
    (&DAT_00a74c0e)[iVar13] = uStack_52;
    (&DAT_00a74c0f)[iVar13] = uStack_51;
    (&DAT_00a74c10)[iVar13] = uStack_50;
    (&DAT_00a74c11)[iVar13] = uStack_4f;
    (&DAT_00a74c12)[iVar13] = uStack_4e;
    (&DAT_00a74c13)[iVar13] = uStack_4d;
    (&DAT_00a74c14)[iVar13] = uStack_4c;
    (&DAT_00a74c15)[iVar13] = uStack_4b;
    (&DAT_00a74c16)[iVar13] = uStack_4a;
    (&DAT_00a74c17)[iVar13] = uStack_49;
    (&DAT_00a74c18)[iVar13] = uStack_48;
    (&DAT_00a74c19)[iVar13] = uStack_47;
    (&DAT_00a74c1a)[iVar13] = uStack_46;
    (&DAT_00a74c1b)[iVar13] = uStack_45;
LAB_0056a9dc:
    DVar8 = WaitForSingleObject((HANDLE)(&DAT_00a74c40)[param_1 * 0x135],0);
    if (DVar8 == 0) {
      ResetEvent((HANDLE)(&DAT_00a74c40)[param_1 * 0x135]);
      return 0;
    }
    return 0;
  }
  iVar7 = (*DAT_00aba168)();
  if (*piVar14 == iVar7) {
    return 0;
  }
  *piVar14 = iVar7;
  if ((DAT_00a82894 == (code *)0x0) ||
     (iVar7 = (*DAT_00a82894)((&DAT_00a74c38)[param_1 * 0x135],(int)register0x00000010 + -0x9c),
     iVar7 != 0)) {
    uVar17 = 0x1a;
    puVar4 = &DAT_00a74c1c;
    goto LAB_0056af15;
  }
  bVar10 = (byte)unaff_EBX;
  (&DAT_00a74c1d)[iVar13] = bVar10 >> 1 & 1;
  (&DAT_00a74c1f)[iVar13] = bVar10 >> 3 & 1;
  (&DAT_00a74c21)[iVar13] = bVar10 >> 5 & 1;
  (&DAT_00a74c1c)[iVar13] = bVar10 & 1;
  (&DAT_00a74c23)[iVar13] = bVar10 >> 7;
  (&DAT_00a74c1e)[iVar13] = bVar10 >> 2 & 1;
  (&DAT_00a74c20)[iVar13] = bVar10 >> 4 & 1;
  (&DAT_00a74c25)[iVar13] = (byte)(unaff_EBX >> 9) & 1;
  (&DAT_00a74c22)[iVar13] = bVar10 >> 6 & 1;
  (&DAT_00a74c27)[iVar13] = (byte)(unaff_EBX >> 0xb) & 1;
  (&DAT_00a74c24)[iVar13] = (byte)(unaff_EBX >> 8) & 1;
  (&DAT_00a74c29)[iVar13] = (byte)(unaff_EBX >> 0xd) & 1;
  (&DAT_00a74c26)[iVar13] = (byte)(unaff_EBX >> 10) & 1;
  (&DAT_00a74c2b)[iVar13] = (byte)(unaff_EBX >> 0xf) & 1;
  bVar18 = (byte)(unaff_EBX >> 0x18);
  (&DAT_00a74c2d)[iVar13] = bVar18;
  (&DAT_00a74c28)[iVar13] = (byte)(unaff_EBX >> 0xc) & 1;
  *(short *)(&DAT_00a74c30 + iVar13) = uStack_94._2_2_;
  (&DAT_00a74c2a)[iVar13] = (byte)(unaff_EBX >> 0xe) & 1;
  bVar10 = (byte)(unaff_EBX >> 0x10);
  *(short *)(&DAT_00a74c32 + iVar13) = (short)uStack_90;
  (&DAT_00a74c2c)[iVar13] = bVar10;
  *(short *)(&DAT_00a74c34 + iVar13) = uStack_90._2_2_;
  iVar7 = (int)(short)uStack_94;
  *(short *)(&DAT_00a74c2e + iVar13) = (short)uStack_94;
  if (iVar7 == -0x8000) {
    *(undefined4 *)(&DAT_00a74bcc + iVar13) = 0xfffffc18;
  }
  else if (iVar7 == 0x7fff) {
    *(undefined4 *)(&DAT_00a74bcc + iVar13) = 1000;
  }
  else {
    sVar5 = (short)((uint)((&DAT_00a74bc8)[param_1 * 0x135] * 0x7fff) >> 0x10);
    iVar16 = (int)sVar5;
    iVar9 = iVar16;
    if (-iVar16 <= iVar7) {
      if ((short)uStack_94 <= sVar5) {
        *(undefined4 *)(&DAT_00a74bcc + iVar13) = 0;
        goto LAB_0056abb5;
      }
      iVar9 = -iVar16;
    }
    *(int *)(&DAT_00a74bcc + iVar13) = ((iVar7 + iVar9) * 1000) / (0x7fff - iVar16);
  }
LAB_0056abb5:
  iVar7 = (int)uStack_94._2_2_;
  if (iVar7 == -0x8000) {
    *(undefined4 *)(&DAT_00a74bd0 + iVar13) = 1000;
  }
  else if (iVar7 == 0x7fff) {
    *(undefined4 *)(&DAT_00a74bd0 + iVar13) = 0xfffffc18;
  }
  else {
    sVar5 = (short)((uint)((&DAT_00a74bc8)[param_1 * 0x135] * 0x7fff) >> 0x10);
    iVar9 = (int)sVar5;
    if (iVar7 < -iVar9) {
      *(int *)(&DAT_00a74bd0 + iVar13) = ((iVar7 + iVar9) * -1000) / (0x7fff - iVar9);
    }
    else if (sVar5 < uStack_94._2_2_) {
      *(int *)(&DAT_00a74bd0 + iVar13) = ((iVar9 - iVar7) * 1000) / (0x7fff - iVar9);
    }
    else {
      *(undefined4 *)(&DAT_00a74bd0 + iVar13) = 0;
    }
  }
  iVar7 = (int)(short)uStack_90;
  if (iVar7 == -0x8000) {
    *(undefined4 *)(&DAT_00a74bd8 + iVar13) = 0xfffffc18;
  }
  else if (iVar7 == 0x7fff) {
    *(undefined4 *)(&DAT_00a74bd8 + iVar13) = 1000;
  }
  else {
    sVar5 = (short)((uint)((&DAT_00a74bc8)[param_1 * 0x135] * 0x7fff) >> 0x10);
    iVar16 = (int)sVar5;
    iVar9 = iVar16;
    if (-iVar16 <= iVar7) {
      if ((short)uStack_90 <= sVar5) {
        *(undefined4 *)(&DAT_00a74bd8 + iVar13) = 0;
        goto LAB_0056ac8f;
      }
      iVar9 = -iVar16;
    }
    *(int *)(&DAT_00a74bd8 + iVar13) = ((iVar7 + iVar9) * 1000) / (0x7fff - iVar16);
  }
LAB_0056ac8f:
  iVar7 = (int)uStack_90._2_2_;
  if (iVar7 == -0x8000) {
    *(undefined4 *)(&DAT_00a74bdc + iVar13) = 1000;
  }
  else if (iVar7 == 0x7fff) {
    *(undefined4 *)(&DAT_00a74bdc + iVar13) = 0xfffffc18;
  }
  else {
    sVar5 = (short)((uint)((&DAT_00a74bc8)[param_1 * 0x135] * 0x7fff) >> 0x10);
    iVar9 = (int)sVar5;
    if (iVar7 < -iVar9) {
      *(int *)(&DAT_00a74bdc + iVar13) = ((iVar7 + iVar9) * -1000) / (0x7fff - iVar9);
    }
    else if (sVar5 < uStack_90._2_2_) {
      *(int *)(&DAT_00a74bdc + iVar13) = ((iVar9 - iVar7) * 1000) / (0x7fff - iVar9);
    }
    else {
      *(undefined4 *)(&DAT_00a74bdc + iVar13) = 0;
    }
  }
  uVar2 = (ushort)unaff_EBX;
  uVar6 = uVar2 & _DAT_0084f3b2;
  (&DAT_00a74bfc)[iVar13] = -((uVar2 & (ushort)_DAT_0084f3b0) != 0) & 0x80;
  uVar3 = (ushort)_DAT_0084f3b4;
  (&DAT_00a74bfd)[iVar13] = -(uVar6 != 0) & 0x80;
  uVar6 = uVar2 & _DAT_0084f3b6;
  (&DAT_00a74bfe)[iVar13] = -((uVar2 & uVar3) != 0) & 0x80;
  uVar3 = (ushort)_DAT_0084f3b8;
  (&DAT_00a74bff)[iVar13] = -(uVar6 != 0) & 0x80;
  uVar6 = uVar2 & _DAT_0084f3ba;
  (&DAT_00a74c00)[iVar13] = -((uVar2 & uVar3) != 0) & 0x80;
  uVar3 = (ushort)_DAT_0084f3bc;
  (&DAT_00a74c01)[iVar13] = -(uVar6 != 0) & 0x80;
  uVar6 = uVar2 & _DAT_0084f3be;
  (&DAT_00a74c02)[iVar13] = -((uVar2 & uVar3) != 0) & 0x80;
  uVar3 = (ushort)_DAT_0084f3c0;
  (&DAT_00a74c03)[iVar13] = -(uVar6 != 0) & 0x80;
  uVar6 = uVar2 & _DAT_0084f3c2;
  (&DAT_00a74c04)[iVar13] = -((uVar2 & uVar3) != 0) & 0x80;
  (&DAT_00a74c05)[iVar13] = -(uVar6 != 0) & 0x80;
  if ((((unaff_EBX & 4) == 0) && ((unaff_EBX & 1) != 0)) && ((unaff_EBX & 8) == 0)) {
    (&DAT_00a74bec)[param_1 * 0x135] = 0;
    goto LAB_0056aea6;
  }
  if (((unaff_EBX & 1) != 0) && ((unaff_EBX & 8) != 0)) {
    (&DAT_00a74bec)[param_1 * 0x135] = 0x1194;
    goto LAB_0056aea6;
  }
  sVar5 = (short)(unaff_EBX & 1);
  if ((sVar5 == 0) && (((unaff_EBX & 8) != 0 && ((unaff_EBX & 2) == 0)))) {
    (&DAT_00a74bec)[param_1 * 0x135] = 9000;
    goto LAB_0056aea6;
  }
  if (((unaff_EBX & 8) != 0) && ((unaff_EBX & 2) != 0)) {
    (&DAT_00a74bec)[param_1 * 0x135] = 0x34bc;
    goto LAB_0056aea6;
  }
  sVar12 = (short)(unaff_EBX & 4);
  if ((((short)(unaff_EBX & 8) == 0) && ((unaff_EBX & 2) != 0)) && (sVar12 == 0)) {
    (&DAT_00a74bec)[param_1 * 0x135] = 18000;
    goto LAB_0056aea6;
  }
  if (((unaff_EBX & 2) != 0) && (sVar12 != 0)) {
    (&DAT_00a74bec)[param_1 * 0x135] = 0x57e4;
    goto LAB_0056aea6;
  }
  if ((short)(unaff_EBX & 2) == 0) {
    if (sVar12 != 0) {
      if (sVar5 == 0) {
        (&DAT_00a74bec)[param_1 * 0x135] = 27000;
        goto LAB_0056aea6;
      }
      goto LAB_0056ae90;
    }
  }
  else {
LAB_0056ae90:
    if ((sVar12 != 0) && (sVar5 != 0)) {
      (&DAT_00a74bec)[param_1 * 0x135] = 0x7b0c;
      goto LAB_0056aea6;
    }
  }
  (&DAT_00a74bec)[param_1 * 0x135] = 0xffffffff;
LAB_0056aea6:
  iVar7 = (int)(short)((uint)((&DAT_00a74bc8)[param_1 * 0x135] * 0xff) >> 0x10);
  (&DAT_00a74bf0)[param_1 * 0x135] = 0xffffffff;
  (&DAT_00a74bf4)[param_1 * 0x135] = 0xffffffff;
  (&DAT_00a74bf8)[param_1 * 0x135] = 0xffffffff;
  *(undefined4 *)(&DAT_00a74bd4 + iVar13) = 0;
  if (iVar7 < (int)(uint)bVar10) {
    *(int *)(&DAT_00a74bd4 + iVar13) = (int)(((uint)bVar10 - iVar7) * 1000) / (0xff - iVar7);
  }
  if (iVar7 < (int)(uint)bVar18) {
    *(int *)(&DAT_00a74bd4 + iVar13) =
         *(int *)(&DAT_00a74bd4 + iVar13) + (int)((iVar7 - (uint)bVar18) * 1000) / (0xff - iVar7);
    return 0;
  }
  return 0;
}

