
undefined4 FUN_00572ff0(uint param_1,int param_2,byte *param_3)

{
  uint uVar1;
  byte bVar2;
  byte bVar3;
  byte bVar4;
  undefined4 uVar5;
  
  bVar2 = (byte)(param_1 >> 8);
  if (param_2 < 0x4e5) {
    if (param_2 == 0x4e4) {
LAB_0057314b:
      if (param_3 != (byte *)0x0) {
        *param_3 = (byte)param_1;
      }
      return 1;
    }
    if (param_2 < 0x3b7) {
      if (((0x3b4 < param_2) || (param_2 == 0x3a4)) || (param_2 == 0x3a8)) {
        if (0xff < param_1) {
          if (param_3 != (byte *)0x0) {
            *param_3 = bVar2;
            param_3[1] = (byte)param_1;
          }
          return 2;
        }
LAB_005731a4:
        if (param_3 != (byte *)0x0) {
          *param_3 = (byte)param_1;
        }
        return 1;
      }
    }
    else if (((0x4af < param_2) && (param_2 < 0x4b2)) && (param_1 < 0x110000)) {
      if (param_1 < 0x10000) {
        uVar1 = 0;
        uVar5 = 2;
      }
      else {
        uVar1 = param_1 & 0x3ff;
        param_1 = (param_1 - 0x10000 & 0xffc00 | 0x3600000) >> 10;
        uVar1 = uVar1 | 0xdc00;
        uVar5 = 4;
      }
      if (param_3 != (byte *)0x0) {
        bVar3 = (byte)(param_1 >> 8);
        bVar2 = (byte)(uVar1 >> 8);
        if (param_2 == 0x4b1) {
          *param_3 = bVar3;
          param_3[1] = (byte)param_1;
          if (uVar1 != 0) {
            param_3[3] = (byte)uVar1;
            param_3[2] = bVar2;
            return uVar5;
          }
        }
        else {
          *param_3 = (byte)param_1;
          param_3[1] = bVar3;
          if (uVar1 != 0) {
            param_3[2] = (byte)uVar1;
            param_3[3] = bVar2;
          }
        }
      }
      return uVar5;
    }
  }
  else {
    bVar3 = (byte)(param_1 >> 0x18);
    if (param_2 < 0x8000) {
      bVar4 = (byte)(param_1 >> 0x10);
      if (param_2 == 0x7fff) {
        if (param_3 != (byte *)0x0) {
          *param_3 = bVar3;
          param_3[1] = bVar4;
          param_3[2] = bVar2;
          param_3[3] = (byte)param_1;
        }
        return 4;
      }
      if (0x7ffb < param_2) {
        if (param_2 < 0x7ffe) goto LAB_0057314b;
        if (param_2 == 0x7ffe) {
          if (param_3 != (byte *)0x0) {
            param_3[1] = bVar2;
            *param_3 = (byte)param_1;
            param_3[2] = bVar4;
            param_3[3] = bVar3;
          }
          return 4;
        }
      }
    }
    else if (param_2 == 0xfde9) {
      if (param_1 < 0x80) goto LAB_005731a4;
      if (param_1 < 0x800) {
        if (param_3 != (byte *)0x0) {
          *param_3 = (byte)(param_1 >> 6) & 0x1f | 0xc0;
          param_3[1] = (byte)param_1 & 0x3f | 0x80;
        }
        return 2;
      }
      if (param_1 < 0x10000) {
        if (param_3 != (byte *)0x0) {
          *param_3 = (byte)(param_1 >> 0xc) & 0xf | 0xe0;
          param_3[1] = (byte)(param_1 >> 6) & 0x3f | 0x80;
          param_3[2] = (byte)param_1 & 0x3f | 0x80;
        }
        return 3;
      }
      if (param_1 < 0x200000) {
        if (param_3 != (byte *)0x0) {
          *param_3 = (byte)(param_1 >> 0x12) & 7 | 0xf0;
          param_3[1] = (byte)(param_1 >> 0xc) & 0x3f | 0x80;
          param_3[2] = (byte)(param_1 >> 6) & 0x3f | 0x80;
          param_3[3] = (byte)param_1 & 0x3f | 0x80;
        }
        return 4;
      }
      if (param_1 < 0x4000000) {
        if (param_3 != (byte *)0x0) {
          *param_3 = bVar3 & 3 | 0xf8;
          param_3[1] = (byte)(param_1 >> 0x12) & 0x3f | 0x80;
          param_3[2] = (byte)(param_1 >> 0xc) & 0x3f | 0x80;
          param_3[3] = (byte)(param_1 >> 6) & 0x3f | 0x80;
          param_3[4] = (byte)param_1 & 0x3f | 0x80;
        }
        return 5;
      }
      if (param_1 < 0x80000000) {
        if (param_3 != (byte *)0x0) {
          *param_3 = bVar3 >> 6 & 1 | 0xfc;
          param_3[1] = bVar3 & 0x3f | 0x80;
          param_3[2] = (byte)(param_1 >> 0x12) & 0x3f | 0x80;
          param_3[3] = (byte)(param_1 >> 0xc) & 0x3f | 0x80;
          param_3[4] = (byte)(param_1 >> 6) & 0x3f | 0x80;
          param_3[5] = (byte)param_1 & 0x3f | 0x80;
        }
        return 6;
      }
    }
  }
  return 0;
}

