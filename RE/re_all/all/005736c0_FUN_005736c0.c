
uint FUN_005736c0(uint param_1,int param_2,int param_3)

{
  bool bVar1;
  
  if (DAT_00b239c0 == 0) {
    FUN_005728b0();
  }
  if (param_2 == param_3) {
    return param_1;
  }
  if (param_2 < 0x4e5) {
    if (param_2 != 0x4e4) {
      if (0x3b6 < param_2) {
        if (param_2 < 0x4b0) {
          return 0;
        }
        if (0x4b1 < param_2) {
          return 0;
        }
        goto LAB_00573882;
      }
      if (((param_2 < 0x3b5) && (param_2 != 0x3a4)) && (param_2 != 0x3a8)) {
        return 0;
      }
    }
LAB_00573708:
    if (param_3 == 0x7ffd) {
      return ~-(uint)(0xff < param_1) & param_1;
    }
    if (param_2 < 0x3b7) {
      if (param_2 == 0x3b6) {
        param_1 = (uint)(ushort)(&DAT_00be39c4)[param_1];
      }
      else if (param_2 == 0x3a4) {
        param_1 = (uint)(ushort)(&DAT_00b239c4)[param_1];
      }
      else if (param_2 == 0x3a8) {
        param_1 = (uint)(ushort)(&DAT_00b639c4)[param_1];
      }
      else {
        if (param_2 != 0x3b5) {
          return 0;
        }
        param_1 = (uint)(ushort)(&DAT_00ba39c4)[param_1];
      }
    }
    else if (param_2 == 0x4e4) {
      param_1 = (uint)(ushort)(&DAT_00c239c4)[param_1];
    }
    else {
      if (param_2 != 0x7ffc) {
        return 0;
      }
      param_1 = (uint)(ushort)(&DAT_00c639c4)[param_1];
    }
    if (param_3 < 0x4b2) {
      if (0x4af < param_3) {
        return param_1;
      }
      switch(param_3) {
      case 0x3a4:
        goto switchD_0057380b_caseD_3a4;
      default:
        return 0;
      case 0x3a8:
switchD_0057380b_caseD_3a8:
        return (uint)*(ushort *)(&DAT_00b839c4 + param_1 * 2);
      case 0x3b5:
switchD_0057380b_caseD_3b5:
        return (uint)*(ushort *)(&DAT_00bc39c4 + param_1 * 2);
      case 0x3b6:
switchD_0057380b_caseD_3b6:
        return (uint)*(ushort *)(&DAT_00c039c4 + param_1 * 2);
      }
    }
    if (0x7fff < param_3) {
      if (param_3 == 0xfde9) {
        return param_1;
      }
      return 0;
    }
    if (0x7ffd < param_3) {
      return param_1;
    }
    if (param_3 == 0x4e4) {
LAB_00573863:
      return (uint)*(ushort *)(&DAT_00c439c4 + param_1 * 2);
    }
    if (param_3 != 0x7ffc) {
      return 0;
    }
  }
  else {
    if (param_2 < 0x8000) {
      if (param_2 < 0x7ffe) {
        if (param_2 != 0x7ffc) {
          bVar1 = param_2 == 0x7ffd;
          goto LAB_00573967;
        }
        goto LAB_00573708;
      }
    }
    else if (param_2 != 0xfde9) {
      return 0;
    }
LAB_00573882:
    if (param_3 < 0x4e5) {
      if (param_3 != 0x4e4) {
        if (0x3b5 < param_3) {
          if (param_3 != 0x3b6) {
            if (param_3 < 0x4b0) {
              return 0;
            }
            if (param_3 < 0x4b2) {
              return param_1;
            }
            return 0;
          }
          if (0xffff < param_1) {
            return 0;
          }
          goto switchD_0057380b_caseD_3b6;
        }
        if (param_3 == 0x3b5) {
          if (0xffff < param_1) {
            return 0;
          }
          goto switchD_0057380b_caseD_3b5;
        }
        if (param_3 != 0x3a4) {
          if (param_3 != 0x3a8) {
            return 0;
          }
          if (0xffff < param_1) {
            return 0;
          }
          goto switchD_0057380b_caseD_3a8;
        }
        if (0xffff < param_1) {
          return 0;
        }
switchD_0057380b_caseD_3a4:
        return (uint)*(ushort *)(&DAT_00b439c4 + param_1 * 2);
      }
      if (0xffff < param_1) {
        return 0;
      }
      goto LAB_00573863;
    }
    if (0x7fff < param_3) {
      bVar1 = param_3 == 0xfde9;
LAB_00573967:
      if (bVar1) {
        return param_1;
      }
      return 0;
    }
    if (0x7ffd < param_3) {
      return param_1;
    }
    if (param_3 != 0x7ffc) {
      if (param_3 == 0x7ffd) {
        return ~-(uint)(0xff < param_1) & param_1;
      }
      return 0;
    }
    if (0xffff < param_1) {
      return 0;
    }
  }
  return (uint)*(ushort *)(&DAT_00c839c4 + param_1 * 2);
}

