
undefined * FUN_00598180(undefined4 param_1)

{
  if (DAT_00ee2308 == 0) {
    DAT_00ee2308 = 1;
    FUN_00544640(&DAT_00ee1ee0,0x18,0xff0000,0xff00,0xff,0,0,0,0);
    FUN_00544640(&DAT_00ee1ab8,0x20,0xff0000,0xff00,0xff,0xff000000,0,0,0);
    FUN_00544640(&DAT_00ee1690,0x20,0xff0000,0xff00,0xff,0,0,0,0);
    FUN_00544640(&DAT_00ee1268,0x10,0xf800,0x7e0,0x1f,0,0,0,0);
    FUN_00544640(&DAT_00ee0e40,0x10,0x7c00,0x3e0,0x1f,0,0,0,0);
    FUN_00544640(&DAT_00ee0a18,0x10,0x7c00,0x3e0,0x1f,0x8000,0,0,0);
    FUN_00544640(&DAT_00ee05f0,0x10,0xf00,0xf0,0xf,0xf000,0,0,0);
    FUN_00544640(&DAT_00ee01c8,8,0xe0,0x1c,3,0,0,0,0);
    FUN_00544640(&DAT_00edfda0,0x10,0xe0,0x1c,3,0xff00,0,0,0);
    FUN_00544640(&DAT_00edf978,0x10,0xf00,0xf0,0xf,0,0,0,0);
    FUN_00544640(&DAT_00edf550,0x20,0x3ff,0xffc00,0x3ff00000,0xc0000000,0,0,0);
    FUN_00544640(&DAT_00edf128,0x20,0xff,0xff00,0xff0000,0xff000000,0,0,0);
    FUN_00544640(&DAT_00eded00,0x20,0xff,0xff00,0xff0000,0,0,0,0);
    FUN_00544640(&DAT_00ede8d8,0x20,0x3ff00000,0xffc00,0x3ff,0xc0000000,0,0,0);
    FUN_00544640(&DAT_00ede4b0,0,0,0,0,0,4,0x10,0);
    FUN_00544640(&DAT_00ede088,0,0,0,0,0,4,0x10,1);
    FUN_00544640(&DAT_00eddc60,0,0,0,0,0,4,0x20,1);
    FUN_00544640(&DAT_00edd838,0,0,0,0,0,1,8,0);
    FUN_00544640(&DAT_00edd410,0,0,0,0,0,1,0x10,0);
    FUN_00544640(&DAT_00edcfe8,0,0,0,0,0,1,0x10,1);
    FUN_00544640(&DAT_00edcbc0,0,0,0,0,0,1,0x20,1);
    FUN_00544640(&DAT_00edc798,0,0,0,0,0,2,8,0);
    FUN_00544640(&DAT_00edc370,0,0,0,0,0,2,0x10,0);
    FUN_00544640(&DAT_00edbf48,0,0,0,0,0,2,0x10,1);
    FUN_00544640(&DAT_00edbb20,0,0,0,0,0,2,0x20,1);
  }
  switch(param_1) {
  case 0x14:
    return &DAT_00ee1ee0;
  case 0x15:
    return &DAT_00ee1ab8;
  case 0x16:
    return &DAT_00ee1690;
  case 0x17:
    return &DAT_00ee1268;
  case 0x18:
    return &DAT_00ee0e40;
  case 0x19:
    return &DAT_00ee0a18;
  case 0x1a:
    return &DAT_00ee05f0;
  case 0x1b:
    return &DAT_00ee01c8;
  default:
    return (undefined *)0x0;
  case 0x1d:
    return &DAT_00edfda0;
  case 0x1e:
    return &DAT_00edf978;
  case 0x1f:
    return &DAT_00edf550;
  case 0x20:
    return &DAT_00edf128;
  case 0x21:
    return &DAT_00eded00;
  case 0x22:
    return &DAT_00edc370;
  case 0x23:
    return &DAT_00ede8d8;
  case 0x24:
    return &DAT_00ede4b0;
  case 0x32:
    return &DAT_00edd838;
  case 0x33:
  case 0x3c:
    return &DAT_00edc798;
  case 0x51:
    return &DAT_00edd410;
  case 0x6f:
    return &DAT_00edcfe8;
  case 0x70:
    return &DAT_00edbf48;
  case 0x71:
    return &DAT_00ede088;
  case 0x72:
    return &DAT_00edcbc0;
  case 0x73:
    return &DAT_00edbb20;
  case 0x74:
    return &DAT_00eddc60;
  }
}

