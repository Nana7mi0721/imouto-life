
void FUN_0056e490(int param_1)

{
  uint uVar1;
  byte *unaff_EBX;
  uint uVar2;
  uint uVar3;
  
  if (param_1 == 0) {
    FUN_0056d380();
  }
  else {
    uVar1 = FUN_005773c0(0x7ffd,param_1);
    if (uVar1 < 0xd) {
      uVar2 = 0;
      uVar3 = uVar1;
      do {
        FUN_0056d420(unaff_EBX + (uVar3 - uVar1),param_1,uVar1);
        uVar3 = uVar3 + uVar1;
        uVar2 = uVar2 + uVar1;
      } while (uVar3 < 0xd);
      if (uVar2 < 0xc) {
        FUN_0056d420(unaff_EBX + uVar2,param_1,0xc - uVar2);
      }
    }
    else {
      FUN_0056d420();
    }
  }
  unaff_EBX[2] = unaff_EBX[2] ^ 0x8a;
  unaff_EBX[5] = unaff_EBX[5] ^ 0xac;
  unaff_EBX[9] = unaff_EBX[9] ^ 0x7f;
  *unaff_EBX = ~*unaff_EBX;
  unaff_EBX[1] = unaff_EBX[1] << 4 | unaff_EBX[1] >> 4;
  unaff_EBX[3] = ~(unaff_EBX[3] << 4 | unaff_EBX[3] >> 4);
  unaff_EBX[4] = ~unaff_EBX[4];
  unaff_EBX[6] = ~unaff_EBX[6];
  unaff_EBX[0xb] = unaff_EBX[0xb] ^ 0xcc;
  unaff_EBX[7] = ~(unaff_EBX[7] >> 3 | unaff_EBX[7] << 5);
  unaff_EBX[8] = unaff_EBX[8] << 3 | unaff_EBX[8] >> 5;
  unaff_EBX[10] = (unaff_EBX[10] << 4 | unaff_EBX[10] >> 4) ^ 0xd6;
  return;
}

