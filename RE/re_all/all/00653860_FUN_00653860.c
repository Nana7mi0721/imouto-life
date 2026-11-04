
undefined4 * FUN_00653860(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 *puVar1;
  char *_Dest;
  
  puVar1 = (undefined4 *)FUN_006507d0(0x24);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  FUN_00650810(puVar1,0,0x24);
  *(undefined2 *)(puVar1 + 1) = 0xfffd;
  *(undefined2 *)((int)puVar1 + 6) = 0xfffd;
  puVar1[2] = param_3;
  *puVar1 = param_2;
  puVar1[3] = 0;
  switch(param_3) {
  case 1:
  case 7:
    puVar1[4] = 0x28;
    puVar1[5] = 0x28;
    break;
  case 2:
    puVar1[4] = 0x27;
    puVar1[5] = 0x27;
    break;
  case 3:
    puVar1[4] = 0x2a;
    puVar1[5] = 0x2a;
    break;
  case 4:
    puVar1[4] = 0x2c;
    puVar1[5] = 0x2c;
    break;
  case 5:
  case 10:
  case 0xb:
    puVar1[4] = 0x30;
    puVar1[5] = 0x30;
    break;
  case 6:
    puVar1[4] = 0x29;
    puVar1[5] = 0x29;
    break;
  case 8:
    puVar1[4] = 0x2b;
    puVar1[5] = 0x2b;
    break;
  case 9:
    puVar1[4] = 0x2d;
    puVar1[5] = 0x2d;
    break;
  case 0xc:
    puVar1[4] = 0x31;
    puVar1[5] = 0x31;
    break;
  case 0xd:
  case 0x12:
    puVar1[4] = 0x32;
    puVar1[5] = 0x32;
    break;
  default:
    puVar1[4] = 0;
    puVar1[5] = 0;
    break;
  case 0x10:
    puVar1[4] = 0x2e;
    puVar1[5] = 0x2e;
    break;
  case 0x11:
    puVar1[4] = 0x2f;
    puVar1[5] = 0x2f;
  }
  *(undefined2 *)(puVar1 + 6) = 0x41;
  *(undefined1 *)((int)puVar1 + 0x1a) = 1;
  *(undefined1 *)((int)puVar1 + 0x1b) = 1;
  _Dest = (char *)FUN_006507d0(0x20);
  puVar1[7] = _Dest;
  if (_Dest == (char *)0x0) {
    FUN_006507e0(puVar1);
    return (undefined4 *)0x0;
  }
  puVar1[8] = 0;
  _sprintf(_Dest,s_Tag__d_00a09b00,param_2);
  return puVar1;
}

