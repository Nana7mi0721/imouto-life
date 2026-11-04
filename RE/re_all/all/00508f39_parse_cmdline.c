
/* Library Function - Single Match
    _parse_cmdline
   
   Library: Visual Studio 2003 Release */

void __cdecl parse_cmdline(undefined4 *param_1,int *param_2)

{
  bool bVar1;
  bool bVar2;
  byte *in_EAX;
  byte *pbVar3;
  byte bVar4;
  byte *in_ECX;
  uint uVar5;
  int *unaff_ESI;
  
  bVar1 = false;
  *unaff_ESI = 0;
  *param_2 = 1;
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = in_ECX;
    param_1 = param_1 + 1;
  }
  do {
    if (*in_EAX == 0x22) {
      bVar1 = !bVar1;
      pbVar3 = in_EAX + 1;
      bVar4 = 0x22;
    }
    else {
      *unaff_ESI = *unaff_ESI + 1;
      if (in_ECX != (byte *)0x0) {
        *in_ECX = *in_EAX;
        in_ECX = in_ECX + 1;
      }
      bVar4 = *in_EAX;
      pbVar3 = in_EAX + 1;
      if (((&DAT_00f48921)[bVar4] & 4) != 0) {
        *unaff_ESI = *unaff_ESI + 1;
        if (in_ECX != (byte *)0x0) {
          *in_ECX = *pbVar3;
          in_ECX = in_ECX + 1;
        }
        pbVar3 = in_EAX + 2;
      }
      if (bVar4 == 0) {
        pbVar3 = pbVar3 + -1;
        goto LAB_00508fb2;
      }
    }
    in_EAX = pbVar3;
  } while ((bVar1) || ((bVar4 != 0x20 && (bVar4 != 9))));
  if (in_ECX != (byte *)0x0) {
    in_ECX[-1] = 0;
  }
LAB_00508fb2:
  bVar1 = false;
  while (*pbVar3 != 0) {
    for (; (*pbVar3 == 0x20 || (*pbVar3 == 9)); pbVar3 = pbVar3 + 1) {
    }
    if (*pbVar3 == 0) break;
    if (param_1 != (undefined4 *)0x0) {
      *param_1 = in_ECX;
      param_1 = param_1 + 1;
    }
    *param_2 = *param_2 + 1;
    while( true ) {
      bVar2 = true;
      uVar5 = 0;
      for (; *pbVar3 == 0x5c; pbVar3 = pbVar3 + 1) {
        uVar5 = uVar5 + 1;
      }
      if (*pbVar3 == 0x22) {
        if ((uVar5 & 1) == 0) {
          if ((bVar1) && (pbVar3[1] == 0x22)) {
            pbVar3 = pbVar3 + 1;
          }
          else {
            bVar2 = false;
          }
          bVar1 = !bVar1;
        }
        uVar5 = uVar5 >> 1;
      }
      for (; uVar5 != 0; uVar5 = uVar5 - 1) {
        if (in_ECX != (byte *)0x0) {
          *in_ECX = 0x5c;
          in_ECX = in_ECX + 1;
        }
        *unaff_ESI = *unaff_ESI + 1;
      }
      bVar4 = *pbVar3;
      if ((bVar4 == 0) || ((!bVar1 && ((bVar4 == 0x20 || (bVar4 == 9)))))) break;
      if (bVar2) {
        if (in_ECX == (byte *)0x0) {
          if (((&DAT_00f48921)[bVar4] & 4) != 0) {
            pbVar3 = pbVar3 + 1;
            *unaff_ESI = *unaff_ESI + 1;
          }
        }
        else {
          if (((&DAT_00f48921)[bVar4] & 4) != 0) {
            *in_ECX = bVar4;
            in_ECX = in_ECX + 1;
            pbVar3 = pbVar3 + 1;
            *unaff_ESI = *unaff_ESI + 1;
          }
          *in_ECX = *pbVar3;
          in_ECX = in_ECX + 1;
        }
        *unaff_ESI = *unaff_ESI + 1;
      }
      pbVar3 = pbVar3 + 1;
    }
    if (in_ECX != (byte *)0x0) {
      *in_ECX = 0;
      in_ECX = in_ECX + 1;
    }
    *unaff_ESI = *unaff_ESI + 1;
  }
  if (param_1 != (undefined4 *)0x0) {
    *param_1 = 0;
  }
  *param_2 = *param_2 + 1;
  return;
}

