
uint FUN_0066af60(int param_1,uint param_2,uint *param_3,uint *param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar1 = *param_3;
  for (uVar3 = *param_4; uVar3 < param_2; uVar3 = uVar3 + 1) {
    switch(*(undefined1 *)(uVar3 + param_1)) {
    case 0x2b:
      uVar2 = 4;
      break;
    default:
      goto switchD_0066af98_caseD_2c;
    case 0x2d:
      uVar2 = 0x84;
      break;
    case 0x2e:
      uVar2 = 0x10;
      break;
    case 0x30:
      uVar2 = 8;
      break;
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x38:
    case 0x39:
      uVar2 = 0x108;
      break;
    case 0x45:
    case 0x65:
      uVar2 = 0x20;
    }
    switch(((uVar2 & 0x3c) - 4) + (uVar1 & 3)) {
    case 0:
      if ((uVar1 & 0x3c) != 0) goto switchD_0066af98_caseD_2c;
      uVar1 = uVar1 | uVar2;
      break;
    default:
      goto switchD_0066af98_caseD_2c;
    case 2:
      if ((uVar1 & 0x3c) != 0) goto switchD_0066af98_caseD_2c;
      uVar1 = uVar1 | 4;
      break;
    case 4:
      if ((uVar1 & 0x10) != 0) {
        uVar1 = uVar1 & 0x1c0 | 0x11;
      }
    case 5:
      uVar1 = uVar1 | uVar2 | 0x40;
      break;
    case 6:
      uVar1 = uVar1 | 0x48;
      break;
    case 0xc:
      if ((uVar1 & 0x10) != 0) goto switchD_0066af98_caseD_2c;
      if ((uVar1 & 8) == 0) {
        uVar1 = uVar1 & 0x1c0 | uVar2 | 1;
      }
      else {
        uVar1 = uVar1 | uVar2;
      }
      break;
    case 0x1c:
    case 0x1d:
      if ((uVar1 & 8) == 0) goto switchD_0066af98_caseD_2c;
      uVar1 = uVar1 & 0x1c0 | 2;
    }
  }
switchD_0066af98_caseD_2c:
  *param_3 = uVar1;
  *param_4 = uVar3;
  return uVar1 >> 3 & 1;
}

