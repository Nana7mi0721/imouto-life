
undefined * FUN_005b85a0(undefined4 param_1)

{
  if (DAT_00f324e0 == 0) {
    FUN_00544640(&DAT_00f320b8,0x10,0xf800,0x7e0,0x1f,0,0,0,0);
    FUN_00544640(&DAT_00f31c90,0x20,0xff,0xff00,0xff0000,0xff000000,0,0,0);
    FUN_00544640(&DAT_00f31868,0x20,0xff0000,0xff00,0xff,0,0,0,0);
    FUN_00544640(&DAT_00f31440,0,0,0,0,0,4,0x10,0);
    FUN_00544640(&DAT_00f31018,0,0,0,0,0,4,0x10,1);
    FUN_00544640(&DAT_00f30bf0,0,0,0,0,0,4,0x20,1);
    FUN_00544640(&DAT_00f307c8,0,0,0,0,0,1,8,0);
    FUN_00544640(&DAT_00f303a0,0,0,0,0,0,1,0x10,0);
    FUN_00544640(&DAT_00f2ff78,0,0,0,0,0,1,0x10,1);
    FUN_00544640(&DAT_00f2fb50,0,0,0,0,0,1,0x20,1);
    FUN_00544640(&DAT_00f2f728,0,0,0,0,0,2,8,0);
    FUN_00544640(&DAT_00f2f300,0,0,0,0,0,2,0x10,0);
    FUN_00544640(&DAT_00f2eed8,0,0,0,0,0,2,0x10,1);
    FUN_00544640(&DAT_00f2eab0,0,0,0,0,0,2,0x20,1);
    DAT_00f324e0 = 1;
  }
  switch(param_1) {
  case 2:
    return &DAT_00f30bf0;
  default:
    return (undefined *)0x0;
  case 10:
    return &DAT_00f31018;
  case 0xb:
    return &DAT_00f31440;
  case 0x10:
    return &DAT_00f2eab0;
  case 0x1c:
    return &DAT_00f31c90;
  case 0x22:
    return &DAT_00f2eed8;
  case 0x23:
    return &DAT_00f2f300;
  case 0x29:
    return &DAT_00f2fb50;
  case 0x31:
    return &DAT_00f2f728;
  case 0x36:
    return &DAT_00f2ff78;
  case 0x38:
    return &DAT_00f303a0;
  case 0x3d:
    return &DAT_00f307c8;
  case 0x55:
    return &DAT_00f320b8;
  case 0x58:
    return &DAT_00f31868;
  }
}

