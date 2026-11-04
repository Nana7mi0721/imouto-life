
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_005bbac0(void)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int local_6c;
  int local_68;
  int local_64;
  int local_60;
  int local_5c;
  int local_58;
  int local_50 [3];
  float local_44;
  undefined4 local_40;
  undefined4 local_3c [7];
  undefined4 auStack_20 [8];
  
  bVar1 = false;
  local_6c = 0;
  local_68 = 0;
  local_40 = 0;
  _memset(local_3c,0,0x3c);
  local_58 = 0;
  local_60 = 0;
  if (DAT_00f3a070 == 0) {
    return 0xffffffff;
  }
  DAT_00ef72e8 = 0;
  DAT_00ef72cc = 1;
  DAT_00ef72e4 = 0;
  local_64 = DAT_00ef72e0;
  if (DAT_00ef72e0 == 0) {
    if (DAT_00a380c8 != 0) {
      local_64 = 0xe;
    }
    if (DAT_00ef7314 != 0) {
      if (DAT_00ef731c == 0) {
LAB_005bbb79:
        if (DAT_00ef72d0 != 1) goto LAB_005bbb87;
      }
      else if (DAT_00ef72f4 == 0) {
LAB_005bbb74:
        if (DAT_00ef72d4 != 1) goto LAB_005bbb79;
      }
      else if (DAT_00ef72f4 != 1) {
        if (DAT_00ef72f4 != 2) goto LAB_005bbb87;
        goto LAB_005bbb74;
      }
      local_64 = 1;
      goto LAB_005bbb87;
    }
LAB_005bbb8f:
    DAT_00f0734c = 0;
    if (DAT_00ef72d8 == -1) {
      DAT_00f13670 = 0;
    }
    else {
      DAT_00f13670 = (uint)(DAT_00ef72d8 != 5);
      local_68 = DAT_00ef72d8;
      local_6c = DAT_00ef72dc;
    }
    DAT_00f13664 = (uint)(DAT_00ef72d8 != -1);
    local_60 = (&DAT_00ef1bc8)[DAT_00f13670 + *(int *)(&DAT_0085fc20 + local_64 * 0x28) * 2];
    DAT_00f0733c = 0;
    if ((DAT_00f07330 != 0) && (DAT_00f07328 == 0)) {
      FUN_005d5220(DAT_00f07330,0,4,0,local_50,0);
      DAT_00f07328 = local_50[0];
    }
    DAT_00f0732c = DAT_00f07328;
  }
  else {
    if (DAT_00ef72e0 == 3) {
      local_64 = 0x10;
    }
LAB_005bbb87:
    if (DAT_00ef7314 == 0) goto LAB_005bbb8f;
    local_5c = 1;
    if ((DAT_00ef72d0 != 0) || (DAT_00ef72d4 != 0)) {
LAB_005bbc4c:
      local_5c = 0;
LAB_005bbc50:
      if (DAT_00ef731c != 0) goto LAB_005bbc58;
      DAT_00f0734c = 0;
      DAT_00f0733c = 1;
      if ((DAT_00f07330 != 0) && (DAT_00f07328 == 0)) {
        FUN_005d5220(DAT_00f07330,0,4,0,local_50,0);
        DAT_00f07328 = local_50[0];
      }
      DAT_00f0732c = DAT_00f07328;
      if (DAT_00ef72d8 == -1) {
        if (DAT_00ef72d4 == 1) {
          local_6c = 0x10;
        }
        else {
          if ((*(int *)(&DAT_0085fc24 + local_64 * 0x28) != 1) ||
             (*(int *)(&DAT_0085fc44 + local_64 * 0x28) != 1)) {
            DAT_00f13664 = 0;
            goto LAB_005bc0e9;
          }
          local_6c = 0;
        }
        DAT_00f13664 = 1;
        local_68 = 5;
LAB_005bc0e9:
        DAT_00f13670 = 0;
      }
      else {
        DAT_00f13664 = 1;
        local_68 = DAT_00ef72d8;
        local_6c = DAT_00ef72dc;
        if (DAT_00ef72d8 == 5) goto LAB_005bc0e9;
        DAT_00f13670 = 1;
      }
      local_58 = 1;
      local_60 = (&DAT_00ef1c00)
                 [DAT_00f13670 +
                  (local_5c +
                  ((uint)(DAT_00ef72ec != 0) + *(int *)(&DAT_0085fc20 + local_64 * 0x28) * 2) * 2) *
                  2];
      local_40 = DAT_00ef7318;
      goto LAB_005bc12b;
    }
    if (DAT_00f13214 == 0) goto LAB_005bbc50;
    if (DAT_00ef731c == 0) goto LAB_005bbc4c;
LAB_005bbc58:
    local_3c[0] = DAT_00ef7320;
    iVar3 = *(int *)(&DAT_0085fc20 + local_64 * 0x28);
    local_58 = 2;
    DAT_00f0733c = 2;
    local_40 = DAT_00ef7318;
    if ((DAT_00f07330 != 0) && (DAT_00f07328 == 0)) {
      FUN_005d5220(DAT_00f07330,0,4,0,local_50,0);
      DAT_00f07328 = local_50[0];
    }
    DAT_00f0732c = DAT_00f07328;
    if (DAT_00ef72f4 == 0) {
      DAT_00f0734c = 0;
      if (DAT_00ef72d8 == -1) {
        if (((DAT_00ef72d4 == 1) || (*(int *)(&DAT_0085fc24 + local_64 * 0x28) == 1)) ||
           (DAT_00ef72d0 == 1)) {
          local_6c = 0;
          local_68 = 5;
          goto LAB_005bbff2;
        }
        DAT_00f13664 = 0;
      }
      else {
        local_68 = DAT_00ef72d8;
        local_6c = DAT_00ef72dc;
LAB_005bbff2:
        DAT_00f13664 = 1;
      }
      DAT_00f13670 = 0;
      local_50[0] = 0x3f800000;
      local_50[1] = 0x3f800000;
      bVar1 = true;
      local_50[2] = 0x3f800000;
      local_44 = (float)DAT_00ef72f8 / (float)_DAT_0081ec30;
      if (DAT_00f13664 != 0) {
        DAT_00f13670 = (uint)(local_68 != 5);
      }
      local_60 = *(int *)(&DAT_00ef1ce0 +
                         (DAT_00f13670 +
                         (local_5c + ((uint)(DAT_00ef72ec != 0) + iVar3 * 2) * 2) * 2) * 4);
    }
    else if (DAT_00ef72f4 == 1) {
      local_50[0] = 0;
      local_50[1] = 0;
      DAT_00f0734c = (uint)(DAT_00ef72fc == 0xff);
      bVar1 = true;
      if (DAT_00ef7300 < 2) {
        local_44 = 0.0;
        DAT_00f13664 = 1;
        local_50[2] = 0x3f800000;
        local_6c = DAT_00ef72fc;
        local_68 = 7;
        local_64 = 0;
        if (((DAT_00ef72d0 != 0) || (DAT_00ef72d4 != 0)) && (DAT_00ef72fc == 0)) {
          local_6c = 1;
        }
        DAT_00f13670 = 1;
      }
      else {
        DAT_00f13664 = 0;
        if (DAT_00ef7300 < 0x41) {
          iVar4 = -((DAT_00ef72fc * 0x500) / 0xff);
          iVar5 = iVar4 + 0x500;
          if (iVar5 < 0x400) {
            iVar5 = iVar5 * 0xff;
            local_44 = -(float)(0xff - ((int)(iVar5 + (iVar5 >> 0x1f & 0x3ffU)) >> 10));
          }
          else {
            iVar4 = (iVar4 + 0x100) * 0x40;
            local_44 = (float)((int)(iVar4 + (iVar4 >> 0x1f & 0xffU)) >> 8);
          }
          local_44 = local_44 / (float)_DAT_0081ec30;
          DAT_00f13670 = 0;
          local_50[2] = _DAT_008298e4;
        }
        else if (DAT_00ef7300 < 0x81) {
          iVar4 = -((DAT_00ef72fc * 0x300) / 0xff);
          iVar5 = iVar4 + 0x300;
          if (iVar5 < 0x200) {
            iVar5 = iVar5 * 0xff;
            local_44 = -(float)(0xff - ((int)(iVar5 + (iVar5 >> 0x1f & 0x1ffU)) >> 9));
          }
          else {
            iVar4 = (iVar4 + 0x100) * 0x80;
            local_44 = (float)((int)(iVar4 + (iVar4 >> 0x1f & 0xffU)) >> 8);
          }
          local_44 = local_44 / (float)_DAT_0081ec30;
          DAT_00f13670 = 0;
          local_50[2] = _DAT_007d103c;
        }
        else {
          iVar4 = -((DAT_00ef72fc << 9) / 0xff);
          iVar5 = iVar4 + 0x200;
          if (iVar5 < 0x100) {
            iVar5 = iVar5 * 0xff;
            local_44 = -(float)(0xff - ((int)(iVar5 + (iVar5 >> 0x1f & 0xffU)) >> 8));
          }
          else {
            iVar4 = (iVar4 + 0x100) * 0xff;
            local_44 = (float)((int)(iVar4 + (iVar4 >> 0x1f & 0xffU)) >> 8);
          }
          local_44 = local_44 / (float)_DAT_0081ec30;
          DAT_00f13670 = 0;
          local_50[2] = 0x3f800000;
        }
      }
      local_60 = *(int *)(&DAT_00ef1dc0 +
                         (DAT_00f13670 +
                         (local_5c + ((uint)(DAT_00ef72ec != 0) + iVar3 * 2) * 2) * 2) * 4);
    }
    else if (DAT_00ef72f4 == 2) {
      DAT_00f0734c = 0;
      if (DAT_00ef72d8 == -1) {
        if (*(int *)(&DAT_0085fc24 + local_64 * 0x28) == 1) {
          DAT_00f13664 = 1;
          local_6c = 0;
          local_68 = 5;
        }
        else {
          DAT_00f13664 = 0;
        }
LAB_005bbd3e:
        DAT_00f13670 = 0;
      }
      else {
        DAT_00f13664 = 1;
        local_68 = DAT_00ef72d8;
        local_6c = DAT_00ef72dc;
        if (DAT_00ef72d8 == 5) goto LAB_005bbd3e;
        DAT_00f13670 = 1;
      }
      local_60 = *(int *)(&DAT_00ef1ea0 +
                         (DAT_00f13670 +
                         (local_5c + ((uint)(DAT_00ef72ec != 0) + iVar3 * 2) * 2) * 2) * 4);
    }
  }
LAB_005bc12b:
  DAT_00f07328 = DAT_00f0732c;
  if (0 < DAT_00a38104) {
    iVar4 = 8;
    iVar3 = 3;
    iVar5 = 0;
    do {
      if ((0 < *(int *)((int)&DAT_00a380f8 + iVar5)) &&
         (iVar2 = FUN_0051c790(*(int *)((int)&DAT_00a380f8 + iVar5),0), iVar2 != 0)) {
        *(undefined4 *)((int)auStack_20 + iVar5) = *(undefined4 *)(*(int *)(iVar2 + 0x450) + 4);
        iVar2 = FUN_005ba900(3,iVar4);
        if ((-1 < iVar2) && (iVar2 = FUN_005baa30(3,iVar4), -1 < iVar2)) {
          FUN_005bab60(3,iVar4);
        }
        FUN_005b90c0(0x15,iVar4);
        local_58 = iVar4 + 1;
      }
      iVar5 = iVar5 + 4;
      iVar4 = iVar4 + 1;
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  if (0 < local_58) {
    FUN_005bba30(0,local_58,&local_40);
  }
  if (DAT_00f13664 == 0) {
    if (DAT_00f1366c != -1) {
      FUN_005bb2e0(0xffffffff);
    }
    if (DAT_00f13668 == 5) goto LAB_005bc251;
    local_68 = 5;
  }
  else {
    if (DAT_00f1366c != local_6c) {
      FUN_005bb2e0(local_6c);
    }
    if (DAT_00f13668 == local_68) goto LAB_005bc251;
  }
  FUN_005bb280(local_68);
LAB_005bc251:
  if (bVar1) {
    FUN_005bb3f0(local_50);
  }
  if (DAT_00f132e0 != local_64) {
    FUN_005bb510(local_64);
  }
  if ((DAT_00f136ec != local_60) && (DAT_00f3a070 != 0)) {
    FUN_005d2b70(local_60,0,0);
    DAT_00f136ec = local_60;
    DAT_00f136e8 = 1;
  }
  return 0;
}

