/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hostname.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsousa <dsousa@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/17 16:44:37 by dsousa            #+#    #+#             */
/*   Updated: 2015/01/17 18:43:10 by dsousa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hostname.hpp"
#include <sys/utsname.h>

Hostname::Hostname() : ProgramComponent()
{
	return ;
}

Hostname::Hostname( Hostname const & cpy ) : ProgramComponent( cpy )
{
	*this = cpy;
}

Hostname::~Hostname()
{

}

Hostname &				Hostname::operator=( Hostname const & lhs )
{
	this->_hostname = lhs.getHostname();

	return (*this);
}

void			Hostname::input( float delta )
{
	(void)delta;

}

void			Hostname::update( float delta )
{
	struct utsname info;
	if(uname(&info) != -1)
		this->_hostname = info.nodename;

	std::cout << this->_hostname << std::endl;
	(void)delta;
}
void			Hostname::graphicRender( GraphicRenderEngine & renderEngine )
{
	(void)renderEngine;

}

std::string		Hostname::getHostname( void ) const
{
	return ( this->_hostname );
}
