
uint FUN_00429e40(char param_1,char param_2,uint *param_3,uint param_4)

{
  if ((param_1 == '\0') && (param_2 == '\0')) {
    *param_3 = 0;
  }
  if (((int)param_4 < 300) || (0x140 < (int)param_4)) {
    if ((DAT_00a148b8 & 0x10) != 0) {
      if (*param_3 == 0x12d) {
        return 0;
      }
      *param_3 = -(uint)(param_1 != '\0') & 0x12d;
      return 0x12d;
    }
    if ((DAT_00a148b8 & 0x20) != 0) {
      if (*param_3 == 0x12e) {
        return 0;
      }
      *param_3 = -(uint)(param_1 != '\0') & 0x12e;
      return 0x12e;
    }
    if ((DAT_00a148b8 & 0x40) != 0) {
      if (*param_3 == 0x12f) {
        return 0;
      }
      *param_3 = -(uint)(param_1 != '\0') & 0x12f;
      return 0x12f;
    }
    if ((DAT_00a148b8 & 0x80) != 0) {
      if (*param_3 == 0x130) {
        return 0;
      }
      *param_3 = -(uint)(param_1 != '\0') & 0x130;
      return 0x130;
    }
    if ((DAT_00a148b8 & 0x100) != 0) {
      if (*param_3 == 0x131) {
        return 0;
      }
      *param_3 = -(uint)(param_1 != '\0') & 0x131;
      return 0x131;
    }
    if ((DAT_00a148b8 & 0x200) != 0) {
      if (*param_3 == 0x132) {
        return 0;
      }
      *param_3 = -(uint)(param_1 != '\0') & 0x132;
      return 0x132;
    }
    if ((DAT_00a148b8 & 0x400) != 0) {
      if (*param_3 == 0x133) {
        return 0;
      }
      *param_3 = -(uint)(param_1 != '\0') & 0x133;
      return 0x133;
    }
    if ((DAT_00a148b8 & 0x800) != 0) {
      if (*param_3 == 0x134) {
        return 0;
      }
      *param_3 = -(uint)(param_1 != '\0') & 0x134;
      return 0x134;
    }
    if ((DAT_00a148b8 & 0x1000) != 0) {
      if (*param_3 == 0x135) {
        return 0;
      }
      *param_3 = -(uint)(param_1 != '\0') & 0x135;
      return 0x135;
    }
    if ((DAT_00a148b8 & 0x2000) != 0) {
      if (*param_3 == 0x136) {
        return 0;
      }
      *param_3 = -(uint)(param_1 != '\0') & 0x136;
      return 0x136;
    }
    if ((DAT_00a148b8 & 0x4000) != 0) {
      if (*param_3 == 0x137) {
        return 0;
      }
      *param_3 = -(uint)(param_1 != '\0') & 0x137;
      return 0x137;
    }
    if ((DAT_00a148b8 & 0x8000) != 0) {
      if (*param_3 == 0x138) {
        return 0;
      }
      *param_3 = -(uint)(param_1 != '\0') & 0x138;
      return 0x138;
    }
    if ((DAT_00a148b8 & 0x10000) != 0) {
      if (*param_3 == 0x139) {
        return 0;
      }
      *param_3 = -(uint)(param_1 != '\0') & 0x139;
      return 0x139;
    }
    if ((DAT_00a148b8 & 0x20000) != 0) {
      if (*param_3 == 0x13a) {
        return 0;
      }
      *param_3 = -(uint)(param_1 != '\0') & 0x13a;
      return 0x13a;
    }
    if ((DAT_00a148b8 & 0x40000) != 0) {
      if (*param_3 == 0x13b) {
        return 0;
      }
      *param_3 = -(uint)(param_1 != '\0') & 0x13b;
      return 0x13b;
    }
  }
  else {
    switch(param_4) {
    case 0x12d:
      if ((DAT_00a148b8 & 0x10) != 0) {
        if (*param_3 == param_4) {
          return 0;
        }
        *param_3 = -(uint)(param_1 != '\0') & param_4;
        return param_4;
      }
      break;
    case 0x12e:
      if ((DAT_00a148b8 & 0x20) != 0) {
        if (*param_3 == param_4) {
          return 0;
        }
        *param_3 = -(uint)(param_1 != '\0') & param_4;
        return param_4;
      }
      break;
    case 0x12f:
      if ((DAT_00a148b8 & 0x40) != 0) {
        if (*param_3 == param_4) {
          return 0;
        }
        *param_3 = -(uint)(param_1 != '\0') & param_4;
        return param_4;
      }
      break;
    case 0x130:
      if ((DAT_00a148b8 & 0x80) != 0) {
        if (*param_3 == param_4) {
          return 0;
        }
        *param_3 = -(uint)(param_1 != '\0') & param_4;
        return param_4;
      }
      break;
    case 0x131:
      if ((DAT_00a148b8 & 0x100) != 0) {
        if (*param_3 == param_4) {
          return 0;
        }
        *param_3 = -(uint)(param_1 != '\0') & param_4;
        return param_4;
      }
      break;
    case 0x132:
      if ((DAT_00a148b8 & 0x200) != 0) {
        if (*param_3 == param_4) {
          return 0;
        }
        *param_3 = -(uint)(param_1 != '\0') & param_4;
        return param_4;
      }
      break;
    case 0x133:
      if ((DAT_00a148b8 & 0x400) != 0) {
        if (*param_3 == param_4) {
          return 0;
        }
        *param_3 = -(uint)(param_1 != '\0') & param_4;
        return param_4;
      }
      break;
    case 0x134:
      if ((DAT_00a148b8 & 0x800) != 0) {
        if (*param_3 == param_4) {
          return 0;
        }
        *param_3 = -(uint)(param_1 != '\0') & param_4;
        return param_4;
      }
      break;
    case 0x135:
      if ((DAT_00a148b8 & 0x1000) != 0) {
        if (*param_3 == param_4) {
          return 0;
        }
        *param_3 = -(uint)(param_1 != '\0') & param_4;
        return param_4;
      }
      break;
    case 0x136:
      if ((DAT_00a148b8 & 0x2000) != 0) {
        if (*param_3 == param_4) {
          return 0;
        }
        *param_3 = -(uint)(param_1 != '\0') & param_4;
        return param_4;
      }
      break;
    case 0x137:
      if ((DAT_00a148b8 & 0x4000) != 0) {
        if (*param_3 == param_4) {
          return 0;
        }
        *param_3 = -(uint)(param_1 != '\0') & param_4;
        return param_4;
      }
      break;
    case 0x138:
      if ((DAT_00a148b8 & 0x8000) != 0) {
        if (*param_3 == param_4) {
          return 0;
        }
        *param_3 = -(uint)(param_1 != '\0') & param_4;
        return param_4;
      }
      break;
    case 0x139:
      if ((DAT_00a148b8 & 0x10000) != 0) {
        if (*param_3 == param_4) {
          return 0;
        }
        *param_3 = -(uint)(param_1 != '\0') & param_4;
        return param_4;
      }
      break;
    case 0x13a:
      if ((DAT_00a148b8 & 0x20000) != 0) {
        if (*param_3 == param_4) {
          return 0;
        }
        *param_3 = -(uint)(param_1 != '\0') & param_4;
        return param_4;
      }
      break;
    case 0x13b:
      if ((DAT_00a148b8 & 0x40000) != 0) {
        if (*param_3 == param_4) {
          return 0;
        }
        *param_3 = -(uint)(param_1 != '\0') & param_4;
        return param_4;
      }
    }
  }
  *param_3 = 0;
  return 0;
}

