
/* WARNING: Function: __security_check_cookie replaced with injection: security_check_cookie */
/* Library Function - Single Match
    _ProcessCodePage
   
   Library: Visual Studio 2003 Release */

void __fastcall _ProcessCodePage(char *param_1)

{
  int iVar1;
  undefined4 uVar2;
  char local_10 [8];
  undefined4 local_8;
  
  local_8 = DAT_0084b484;
  if (((param_1 == (char *)0x0) || (*param_1 == '\0')) ||
     (iVar1 = _strcmp(param_1,(char *)&PTR_DAT_007d3f80), iVar1 == 0)) {
    uVar2 = 0x1004;
  }
  else {
    iVar1 = _strcmp(param_1,(char *)&PTR_LAB_007d3f7c);
    if (iVar1 != 0) goto LAB_00505972;
    uVar2 = 0xb;
  }
  iVar1 = (*DAT_00a1fdf4)(DAT_00a1fddc,uVar2,local_10,8);
  if (iVar1 == 0) {
    return;
  }
  param_1 = local_10;
LAB_00505972:
  _atol(param_1);
  return;
}

