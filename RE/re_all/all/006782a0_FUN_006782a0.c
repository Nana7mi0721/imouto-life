
uint FUN_006782a0(undefined4 param_1,byte *param_2,byte *param_3)

{
  bool bVar1;
  byte bVar2;
  byte *pbVar3;
  uint uVar4;
  byte bVar5;
  undefined1 local_100 [256];
  
  bVar1 = true;
  uVar4 = 0;
  bVar5 = 0;
  if (param_2 == (byte *)0x0) {
    *param_3 = 0;
    return 0;
  }
  bVar2 = *param_2;
  pbVar3 = param_2;
  if (bVar2 != 0) {
    do {
      if (0x4e < uVar4) break;
      pbVar3 = pbVar3 + 1;
      if (((bVar2 < 0x21) || (0x7e < bVar2)) && (bVar2 < 0xa1)) {
        if (bVar1) {
          if (bVar5 == 0) goto LAB_0067831a;
        }
        else {
          *param_3 = 0x20;
          param_3 = param_3 + 1;
          uVar4 = uVar4 + 1;
          bVar1 = true;
          if (bVar2 != 0x20) {
LAB_0067831a:
            bVar5 = bVar2;
          }
        }
      }
      else {
        *param_3 = bVar2;
        param_3 = param_3 + 1;
        uVar4 = uVar4 + 1;
        bVar1 = false;
      }
      bVar2 = *pbVar3;
    } while (bVar2 != 0);
    if ((uVar4 != 0) && (bVar1)) {
      uVar4 = uVar4 - 1;
      param_3 = param_3 + -1;
      if (bVar5 == 0) {
        bVar5 = 0x20;
      }
    }
  }
  *param_3 = 0;
  if (uVar4 == 0) {
    return 0;
  }
  if (*pbVar3 != 0) {
    FUN_006687b0(param_1,s_keyword_truncated_00a0d600);
    return uVar4;
  }
  if (bVar5 != 0) {
    FUN_00668800(local_100,1,param_2);
    FUN_00668830(local_100,2,4,bVar5);
    FUN_00668880(param_1,local_100,s_keyword___1___bad_character__0x__00a0d5dc);
  }
  return uVar4;
}

