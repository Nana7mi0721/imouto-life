
undefined4
FUN_0056e970(int *param_1,int param_2,int param_3,int param_4,int param_5,undefined4 param_6,
            int param_7)

{
  int *piVar1;
  int *piVar2;
  ushort uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  int iVar8;
  
  iVar6 = 0;
  if (param_4 != 0) {
    param_5 = 0;
  }
  if ((param_1[0xf] != 0) || (param_1[0x10] != 0)) {
    return 0xffffffff;
  }
  piVar2 = param_1 + 0x216;
  FUN_0056e490(param_6);
  if (param_7 == 0) {
    FUN_0056d380(param_1 + 0x16,0,0x800);
  }
  else {
    FUN_0056cf70(param_1 + 0x16,0x800,param_7);
  }
  param_1[0x11] = 0;
  param_1[0x10] = 0;
  if (param_4 == 0) {
    param_1[0x10] = param_2;
    iVar5 = param_2;
  }
  else {
    iVar6 = FUN_0056e030(param_3,"..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x421);
    param_1[0x10] = iVar6;
    if (iVar6 == 0) {
      return 0xffffffff;
    }
    FUN_0056d420(iVar6,param_2,param_3);
    iVar5 = param_1[0x10];
    iVar6 = param_2;
  }
  param_1[0x220] = iVar6;
  piVar1 = param_1 + 2;
  *param_1 = 0;
  FUN_0056d420(piVar1,iVar5,4);
  FUN_0056e590(4,0,0,0,piVar2);
  iVar6 = param_3 >> 0x1f;
  if ((short)*piVar1 != 0x5844) {
    FUN_0056d380(piVar2,0xff,0xc);
    FUN_0056d420(piVar1,iVar5,4);
    FUN_0056e590(4,0,0,0,piVar2);
    if ((short)*piVar1 != 0x5844) goto LAB_0056ed77;
  }
  uVar3 = *(ushort *)((int)param_1 + 10);
  if (5 < uVar3) {
    *param_1 = 0;
    param_1[0xc] = 0;
    param_1[0xd] = 0;
    FUN_0056d420(piVar1,iVar5,0x30);
    FUN_0056e590(0x30,0,0,0,piVar2);
    if (((short)*piVar1 != 0x5844) || (6 < *(ushort *)((int)param_1 + 10))) goto LAB_0056ed77;
    uVar4 = param_1[0xc];
    if ((param_1[0xd] == 0) && (uVar4 < 0xfdea)) {
      if (uVar4 < 0x4e5) {
        if (uVar4 != 0x4e4) {
          if (uVar4 < 0x3b7) {
            if ((uVar4 < 0x3b5) && (uVar4 != 0x3a4)) {
              bVar7 = uVar4 == 0x3a8;
              goto LAB_0056eb09;
            }
          }
          else if ((uVar4 < 0x4b0) || (0x4b1 < uVar4)) goto LAB_0056eb0b;
        }
      }
      else if (uVar4 < 0x8000) {
        if (uVar4 < 0x7ffe) {
          bVar7 = uVar4 == 0x7ffc;
LAB_0056eb09:
          if (!bVar7) goto LAB_0056eb0b;
        }
      }
      else if (uVar4 != 0xfde9) goto LAB_0056eb0b;
      param_1[0xe] = param_1[0xc];
    }
    else {
LAB_0056eb0b:
      param_1[0xe] = 0x3a4;
    }
    if (param_5 == 0) {
      param_1[0x11] = param_1[6] + param_1[0x10];
LAB_0056eb8a:
      FUN_0056e590(param_1[3],0,0,0,piVar2);
      iVar5 = param_1[0x11];
      param_1[0x14] = iVar5;
      param_1[0x12] = param_1[8] + iVar5;
      iVar5 = param_1[10] + iVar5;
      param_1[0x219] = 1;
      param_1[0x21a] = 1;
      param_1[0x21c] = param_3;
      param_1[0x13] = iVar5;
      param_1[0x15] = iVar5;
      param_1[0x21d] = iVar6;
      param_1[0x21e] = param_4;
      param_1[0x21f] = param_5;
      if (param_5 == 0) {
        FUN_0056e7c0(param_1,iVar5);
        return 0;
      }
      return 0;
    }
    iVar5 = FUN_0056e030(param_1[3],"..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x47c);
    param_1[0x11] = iVar5;
    if (iVar5 != 0) {
      FUN_0056d420(iVar5,param_1[6] + param_1[0x10],param_1[3]);
      goto LAB_0056eb8a;
    }
    goto LAB_0056ed77;
  }
  *param_1 = 1;
  if (5 < uVar3) goto LAB_0056ed77;
  if (param_5 == 0) {
    if (uVar3 < 5) {
      FUN_0056e590(param_3,iVar6,0,0,piVar2);
    }
    if (*(ushort *)((int)param_1 + 10) < 5) {
      FUN_0056d420(piVar1,iVar5,0x18);
    }
    else {
      FUN_0056d420(piVar1,iVar5,0x18);
      FUN_0056e590(0x18,0,0,0,piVar2);
    }
    if (((short)*piVar1 != 0x5844) || (uVar3 = *(ushort *)((int)param_1 + 10), 5 < uVar3))
    goto LAB_0056ed77;
    if (uVar3 < 4) {
      param_1[8] = 0x3a4;
LAB_0056ee6b:
      param_1[0xe] = 0x3a4;
    }
    else {
      param_1[8] = *(uint *)(iVar5 + 0x18);
      if (4 < uVar3) {
        FUN_0056e590(4,0,0x18,0,piVar2);
      }
      uVar4 = param_1[8];
      if (uVar4 < 0x4e5) {
        if (uVar4 != 0x4e4) {
          if (uVar4 < 0x3b7) {
            if ((uVar4 < 0x3b5) && (uVar4 != 0x3a4)) {
              bVar7 = uVar4 == 0x3a8;
              goto LAB_0056ee5c;
            }
          }
          else if ((uVar4 < 0x4b0) || (0x4b1 < uVar4)) goto LAB_0056ee6b;
        }
      }
      else {
        if (uVar4 < 0x8000) {
          if (0x7ffd < uVar4) goto LAB_0056ee5e;
          bVar7 = uVar4 == 0x7ffc;
        }
        else {
          bVar7 = uVar4 == 0xfde9;
        }
LAB_0056ee5c:
        if (!bVar7) goto LAB_0056ee6b;
      }
LAB_0056ee5e:
      param_1[0xe] = uVar4;
    }
    param_1[0x11] = param_1[5] + param_1[0x10];
    if (*(ushort *)((int)param_1 + 10) < 5) goto LAB_0056ee93;
LAB_0056ee83:
    iVar8 = param_1[3];
    iVar5 = 0;
  }
  else {
    if (uVar3 < 4) {
      FUN_0056d420(piVar1,iVar5,0x18);
      FUN_0056e590(0x18,0,0,0,piVar2);
      param_1[8] = 0x3a4;
LAB_0056ecc1:
      param_1[0xe] = 0x3a4;
    }
    else {
      FUN_0056d420(piVar1,iVar5,0x1c);
      FUN_0056e590(0x1c,0,0,0,piVar2);
      uVar4 = param_1[8];
      if (uVar4 < 0x4e5) {
        if (uVar4 != 0x4e4) {
          if (uVar4 < 0x3b7) {
            if ((uVar4 < 0x3b5) && (uVar4 != 0x3a4)) {
              bVar7 = uVar4 == 0x3a8;
              goto LAB_0056ec96;
            }
          }
          else if ((uVar4 < 0x4b0) || (0x4b1 < uVar4)) goto LAB_0056ecc1;
        }
      }
      else {
        if (uVar4 < 0x8000) {
          if (0x7ffd < uVar4) goto LAB_0056ec98;
          bVar7 = uVar4 == 0x7ffc;
        }
        else {
          bVar7 = uVar4 == 0xfde9;
        }
LAB_0056ec96:
        if (!bVar7) goto LAB_0056ecc1;
      }
LAB_0056ec98:
      param_1[0xe] = uVar4;
    }
    iVar5 = FUN_0056e030(param_1[3],"..\\..\\..\\..\\Source\\Library\\Main\\DxArchive_.cpp",0x4d0);
    param_1[0x11] = iVar5;
    if (iVar5 == 0) {
LAB_0056ed77:
      if (param_4 == 0) {
        if (param_5 == 0) {
          if ((*param_1 != 0) && (*(ushort *)((int)param_1 + 10) < 5)) {
            FUN_0056e590(param_3,iVar6,0,0,piVar2);
          }
        }
        else if (param_1[0x11] != 0) {
          FUN_0056e1d0(param_1[0x11]);
          param_1[0x11] = 0;
          return 0xffffffff;
        }
      }
      else if (param_1[0x10] != 0) {
        FUN_0056e1d0(param_1[0x10]);
        param_1[0x10] = 0;
        return 0xffffffff;
      }
      return 0xffffffff;
    }
    FUN_0056d420(iVar5,param_1[0x10] + param_1[5],param_1[3]);
    if (4 < *(ushort *)((int)param_1 + 10)) goto LAB_0056ee83;
    iVar5 = param_1[5];
    iVar8 = param_1[3];
  }
  FUN_0056e590(iVar8,0,iVar5,0,piVar2);
LAB_0056ee93:
  iVar5 = param_1[0x11];
  param_1[0x14] = iVar5;
  param_1[0x12] = param_1[6] + iVar5;
  iVar5 = param_1[7] + iVar5;
  param_1[0x219] = 1;
  param_1[0x21a] = 1;
  param_1[0x21c] = param_3;
  param_1[0x21e] = param_4;
  param_1[0x13] = iVar5;
  param_1[0x15] = iVar5;
  param_1[0x21d] = iVar6;
  param_1[0x21f] = param_5;
  if ((param_5 == 0) && (4 < *(ushort *)((int)param_1 + 10))) {
    FUN_0056e8a0(param_1,iVar5);
  }
  return 0;
}

